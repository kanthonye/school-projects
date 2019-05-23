//
//  Parser.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Parser.hpp"

FunCallStatement* Parser::NewFunCallStatement(const std::string& id)
{
    FunCall* fun_call = NewFunCall(id);
    if ( state == State::Semicolon )
    {
        getToken();
        return new FunCallStatement(fun_call);
    }
    else
    {
        if (fun_call != nullptr) {
            delete fun_call;
            fun_call = nullptr;
        }
        errorMsg(6);
        return nullptr;
    }
}

ArrayVar* Parser::NewArrayVar(const std::string& id)
{    // <array name> and "[" already extracted; start parsing <E list> "]".
    EList* elist = NewEList();
    if ( state == State::RBracket )
    {
        getToken();
        return new ArrayVar(new ArrayName(id), elist);
    }
    else
    {
        errorMsg(5);
        return nullptr;
    }
}

ExprList* Parser::NewExprList()
{
    std::vector<Expr*>* expr_list = new std::vector<Expr*>();
    expr_list->push_back( NewExpr() );
    while ( state == State::Comma )
    {
        getToken();
        expr_list->push_back( NewExpr() );
    }
    return new ExprList(expr_list);
}

FunCall* Parser::NewFunCall(const std::string& id)
{    // <fun name> and "(" already extracted; start parsing <expr list> ")".
    
    FunName* fun_name = new FunName(id);
    //getToken();
    if ( state == State::RParen ) // Parameters <expr list> is non-existent.
    {
        getToken();
        return new FunCall(fun_name , nullptr );
    }
    else
    {
        ExprList* expr_list = NewExprList();
        if ( state == State::RParen )
        {
            getToken();
            return new FunCall(fun_name, expr_list);
        }
        else
        {
            if (expr_list != nullptr)
            {
                delete expr_list;
                expr_list = nullptr;
            }
            errorMsg(1);
            return nullptr;
        }
    }
}

FunCallPrimary* Parser::NewFunCallPrimary(const std::string& id)
{
    return new FunCallPrimary(NewFunCall(id));;
}

Primary* Parser::NewPrimary()
{
    switch ( state.val )
    {
        case State::Id:
        {
            std::string id = t;
            getToken();
            if ( state == State::LParen ) // <fun call primary>
            {
                getToken();
                return NewFunCallPrimary(id);
            }
            else if ( state == state.LBracket ) // <array var>
            {
                getToken();
                return new VarPrimary(NewArrayVar(id));
            }
            else // <id var>
                return new VarPrimary(new IDVar(id));
        }
            
        case State::Keyword_returnVal:
            getToken();
            return new VarPrimary(new ReturnVal);
            
        case State::Int:
        {
            Int* intElem = new Int(t);
            getToken();
            return intElem;
        }
            
        case State::Float:
        case State::FloatE:
        {
            Float* floatElem = new Float(t);
            getToken();
            return floatElem;
        }
            
        case State::LParen:
        {
            getToken();
            Expr* expr = NewExpr();
            if ( state == State::RParen )
            {
                getToken();
                return new Parenthesized(expr);
            }
            else
            {
                if (expr != nullptr)
                {
                    delete expr;
                    expr = nullptr;
                }
                errorMsg(1);
                return nullptr;
            }
        }
            
        case State::Sub:
        {
            getToken();
            return new NegPrimary(NewPrimary());
        }
            
        case State::Inv:
        {
            getToken();
            return new InvPrimary(NewPrimary());
        }
            
        default:
            errorMsg(10);
            return nullptr;
    }
    return 0;
}

BoolPrimary* Parser::NewBoolPrimary()
{
    E* e1 = NewE();
    if ( state.isCompOp() )
    {
        State compOp = state;
        getToken();
        E* e2 = NewE();
        switch( compOp.val )
        {
            case State::Lt: return new  LT(e1, e2);
            case State::Le: return new  LE(e1, e2);
            case State::Gt: return new  GT(e1, e2);
            case State::Ge: return new  GE(e1, e2);
            case State::Eq: return new  Eq(e1, e2);
            default:        return new NEq(e1, e2);
        }
    }
    else
         return new BoolPrimary(e1);
}

BoolTerm* Parser::NewBoolTerm()
{
    std::vector<BoolPrimaryElem*>* blist = new std::vector<BoolPrimaryElem*>();
    blist->push_back( new BoolPrimaryElem( NewBoolPrimary() ) );
    
    while ( state == State::And )
    {
        getToken();
        blist->push_back( new BoolPrimaryAnd( NewBoolPrimary() ) );
    }
    return new BoolTerm(blist);
}

Expr* Parser::NewExpr() // ⟨expr⟩ → ⟨boolTerm⟩ { || ⟨boolTerm⟩ }
{
    std::vector<BoolTermElem*>* blist = new std::vector<BoolTermElem*>();
    blist->push_back( new BoolTermElem( NewBoolTerm() ) );
    while ( state == State::Or )
    {
        getToken();
        blist->push_back( new BoolTermOr( NewBoolTerm() ) );
    }
    return new Expr(blist);
}

Term* Parser::NewTerm() // ⟨term⟩ → ⟨primary⟩ { (*|/) ⟨primary⟩ }
{
    std::vector<PrimaryElem*>* primary_list = new std::vector<PrimaryElem*>();
    primary_list->push_back(new PrimaryElem(NewPrimary()));
    
    while ( state == State::Mul | state == State::Div )
    {
        State op = state;
        getToken();
        Primary* primary = NewPrimary();
        if ( op == State::Mul )
            primary_list->push_back(new MulPrimary(primary));
        else // op == State.Div
            primary_list->push_back(new DivPrimary(primary));
    }
    return new Term(primary_list);
}

E* Parser::NewE() // <E> --> <term> { (+|-) <term> }
{
    std::vector<TermElem*>* terms = new std::vector<TermElem*>();
    terms->push_back( new TermElem(NewTerm()) );
    
    while (state == State::Add || state == State::Sub)
    {
        State op = state;
        getToken();
        Term* term = NewTerm();
        if (op == State::Add)
            terms->push_back(new AddTerm(term));
        else // op == State.Minus
            terms->push_back(new SubTerm(term));
    }
    return new E(terms);
}

EList* Parser::NewEList() // ⟨E list⟩ → ⟨E⟩ { "," ⟨E⟩ }
{
    std::vector<E*>* elist = new std::vector<E*>();
    elist->push_back(NewE());
    
    while ( state == State::Comma )
    {
        getToken();
        elist->push_back(NewE());
    }
    return new EList(elist);
}

Statement* Parser::NewStatement() // ⟨statement⟩ → ⟨assignment⟩ | ⟨cond⟩ | ⟨while⟩ | ⟨block⟩ | ⟨fun call statement⟩ | ⟨print⟩
{
    switch ( state.val )
    {
        case State::Id: // <assignment> or <fun call statement>
        {
            std::string id = t;
            if (id.empty())
                state = State::UNDEF;
            
            getToken();
            if ( state == State::LParen ) // <fun call statement>
            {
                getToken();
                return new Statement(NewFunCallStatement(id));
            }
            else if ( state == state.LBracket ) // <assignment> to <array var>
            {
                getToken();
                return new Statement( NewAssignment( new Var(NewArrayVar(id)) ) );
            }
            else // <assignment> to <id var>
                return new Statement( NewAssignment( new Var(new IDVar(id)) ));
        }
            
        case State::Keyword_returnVal: // <assignment> to returnVal
            getToken();
            return new Statement( NewAssignment(new Var(new ReturnVal)));
            
        case State::Keyword_if:
            return new Statement( NewCond() );
            
        case State::Keyword_while:
            return new Statement( NewWhile() );
            
        case State::LBrace:
            return new Statement( NewBlock() );
            
        case State::Keyword_print:
            return new Statement( NewPrint() );
            
        default:
            errorMsg(4);
            return nullptr;
    }
}

SList* Parser::NewSList()
{
    std::vector<Statement*>* slist = new std::vector<Statement*>();
    while ( BeginsStatement() )
    {
        slist->push_back( NewStatement() );
    }
    return new SList(slist);
}

RightSide* Parser::NewRightSide() // ⟨right side⟩ → ⟨array constructor⟩ | ⟨expr right side⟩
{
    if ( state == State::Keyword_new )
    {
        getToken();
        return new RightSide( NewArrayConstructor() );
    }
    else
    {
        return new RightSide( NewExprRightSide() );
    }
}

Assignment* Parser::NewAssignment(Var* var) // ⟨assignment⟩ → ⟨var⟩ "=" ⟨right side⟩ ";"
{
    if ( state == State::Assign )
    {
        getToken();
        RightSide* rightSide = NewRightSide();
        if ( state == State::Semicolon )
        {
            getToken();
            return new Assignment(var, rightSide);
        }
        else
        {
            errorMsg(6);
            return new Assignment(var, rightSide);
        }
    }
    else
    {
        errorMsg(7);
        return nullptr;
    }
}

Var* Parser::NewVar() // ⟨var⟩ → ⟨id var⟩ | ⟨array var⟩ | "returnVal"
{
    switch (state.val)
    {
        case State::Id:
        {
            std::string id = t;
            getToken();
            if ( state == state.LBracket ) // <array var>
            {
                getToken();
                return new Var(NewArrayVar(id));
            }
            else // <id var>
                return new Var(new IDVar(id));
        }
            
        case State::Keyword_returnVal:
            getToken();
            return new Var(new ReturnVal);
            
        default:
            errorMsg(13);
            return nullptr;
    }
}

ExprRightSide* Parser::NewExprRightSide()
{
    return new ExprRightSide(NewExpr());
}

ArrayConstructor* Parser::NewArrayConstructor() // ⟨array constructor⟩ → "new" "[" ⟨E list⟩ "]"
{    // "new" already extracted; start parsing "[" <E list> "]"
    
    if ( state == State::LBracket )
    {
        getToken();
        EList* eList = NewEList();
        if ( state == State::RBracket )
        {
            getToken();
            return new ArrayConstructor(eList);
        }
        else
        {
            if (eList != nullptr) {
                delete eList;
                eList = nullptr;
            }
            errorMsg(5);
            return nullptr;
        }
    }
    else
    {
        errorMsg(8);
        return nullptr;
    }
}

Cond* Parser::NewCond() // ⟨cond⟩ → "if" "(" ⟨expr⟩ ")" ⟨statement⟩ [ "else" ⟨statement⟩ ]
{
    getToken(); // flush "if"
    if ( state == State::LParen )
    {
        getToken();
        Expr* expr = NewExpr();
        if ( state == State::RParen )
        {
            getToken();
            Statement* statement1 = NewStatement();
            if ( state == State::Keyword_else )
            {
                getToken();
                Statement* statement2 = NewStatement();
                return new If2(expr, statement1, statement2);
            }
            else
                return new If1(expr, statement1);
        }
        else
            errorMsg(1);
    }
    else
        errorMsg(2);
    return nullptr;
}

While* Parser::NewWhile() // <while> --> "while" "(" <expr> ")" <statement>
{
    getToken(); // flush "while"
    if ( state == State::LParen )
    {
        getToken();
        Expr* expr = NewExpr();
        if ( state == State::RParen )
        {
            getToken();
            return new While(expr, NewStatement());
        }
        else
            errorMsg(1);
    }
    else
        errorMsg(2);
    return nullptr;
}

Block* Parser::NewBlock() // <block> --> "{" <s list> "}"
{
    getToken(); // flush "{"
    SList* slist = NewSList();
    if ( state == State::RBrace )
    {
        getToken();
        return new Block(slist);
    }
    else
    {
        errorMsg(9);
        return nullptr;
    }
}
bool Parser::BeginsStatement()
{
    return (state == State::Id || state == State::Keyword_returnVal ||
            state == State::Keyword_if || state == State::Keyword_while ||
            state == State::LBrace || state == State::Keyword_print);
}

Print* Parser::NewPrint() // <print> --> "print" <expr> ";"
{
    getToken(); // flush "print"
    Expr* expr = NewExpr();
    if ( state == State::Semicolon )
    {
        getToken();
        return new Print(expr);
    }
    else
    {
        errorMsg(6);
        return nullptr;
    }
}

Parameter* Parser::NewParameter() // <parameter> --> <id>
{
    if ( state == State::Id && !t.empty() )
    {
        Parameter* parameter = new Parameter(t);
        getToken();
        return parameter;
    }
    else
    {
        errorMsg(12);
        return nullptr;
    }
}

ParameterList* Parser::NewParameterList() // <parameter list> --> <parameter> { "," <parameter> }
{
    std::vector<Parameter*>* parameters = new std::vector<Parameter*>();
    parameters->push_back( NewParameter() );
    
    while ( state == State::Comma )
    {
        getToken();
        parameters->push_back( NewParameter() );
    }
    return new ParameterList(parameters);
}

Header* Parser::NewHeader() // <header> --> <fun name> "(" [ <parameter list> ] ")"
{
    if ( state == State::Id && !t.empty() ) // The token is <fun name>.
    {
        FunName* fun_name = new FunName(t);
        getToken();
        if ( state == State::LParen )
        {
            getToken();
            if ( state == State::RParen ) // <parameter list> is non-existent.
            {
                getToken();
                return new Header(fun_name, nullptr);
            }
            else
            {
                ParameterList* parameter_list = NewParameterList();
                if ( state == State::RParen )
                {
                    getToken();
                    return new Header(fun_name, parameter_list);
                }
                else
                    errorMsg(1);
            }
        }
        else
            errorMsg(2);
    }
    else
        errorMsg(3);
    return nullptr;
}

Body* Parser::NewBody() // <body> --> "{" <s list> "}"
{
    if ( state == State::LBrace )
    {
        getToken();
        SList* sList = NewSList();
        if ( state == State::RBrace )
        {
            getToken();
            return new Body(sList);
        }
        else
        {
            if (sList != nullptr)
            {
                delete sList;
                sList = nullptr;
            }
            errorMsg(State::RBrace);
            return nullptr;
        }
    }
    else
    {
        errorMsg(State::LBrace);
        return nullptr;
    }
}

FunDef* Parser::NewFunDef() // <fun def> --> <header> <body>
{
    Header* header = NewHeader();
    Body* body = NewBody();
    FunDef* fundef = new FunDef(header, body);
    if (header != nullptr)
    {
        functmap.put(header->fun_name->id, fundef);
    }
    return fundef;
}

FunDefList* Parser::NewFunDefList() // <fun def list> --> { <fun def> }+
{
    std::vector<FunDef*>* funDefList = new std::vector<FunDef*>();
    funDefList->push_back( NewFunDef() );
    while ( state == State::Id ) // Parse <fun def> as long as the token is <fun name>.
    {
        funDefList->push_back( NewFunDef() );
        
    }
    return new FunDefList(funDefList);
}

void Parser::errorMsg(int i)
{
    syntaxErrorFound = true;
    state = State::UNDEF;
    Write("%s", (t + " : Syntax Error, unexpected symbol where").c_str());
    
    switch( i )
    {
        case 1:  WriteLn(" ) expected"); return;
        case 2:  WriteLn(" ( expected"); return;
        case 3:  WriteLn(" function name expected"); return;
        case 4:  WriteLn(" id, returnVal, if, while, {, or print expected"); return;
        case 5:  WriteLn(" ] expected"); return;
        case 6:  WriteLn(" ; expected"); return;
        case 7:  WriteLn(" = expected"); return;
        case 8:  WriteLn(" [ expected"); return;
        case State::RBrace:  WriteLn(" } expected"); return;
        case 10: WriteLn(" id, returnVal, int, float, (, -, or ! expected"); return;
        case State::LBrace: WriteLn(" { expected"); return;
        case 12: WriteLn(" function parameter expected"); return;
        case 13: WriteLn(" id or returnVal expected"); return;
    }
}
Parser::Parser()
:   syntaxErrorFound(false)
{}

void Parser::TestParser(const std::string& infile, const std::string& outfile)
{
    SetIO(infile, outfile);
    SetLex();
    
    driver();
    
    if ( state == State::Id )
    {
        FunDefList* funclist = NewFunDefList();
        funclist->PrintParseTree(0, 0);
        delete funclist;
    }

    CloseIO();
}

HashMap<FunDef*> Parser::functmap;
