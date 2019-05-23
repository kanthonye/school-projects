//
//  Parser.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp
#include "../CS316/Eq.hpp"
#include "../CS316/LE.hpp"
#include "../CS316/LT.hpp"
#include "../CS316/GE.hpp"
#include "../CS316/GT.hpp"
#include "../CS316/NEq.hpp"
#include "../CS316/IDVar.hpp"
#include "../CS316/If1.hpp"
#include "../CS316/If2.hpp"
#include "../CS316/EList.hpp"
#include "../CS316/AddTerm.hpp"
#include "../CS316/SubTerm.hpp"
#include "../CS316/Block.hpp"
#include "../CS316/While.hpp"
#include "../CS316/ReturnVal.hpp"
#include "../CS316/Parenthesized.hpp"
#include "../CS316/FunCallStatement.hpp"
#include "../CS316/ArrayVar.hpp"
#include "../CS316/EList.hpp"
#include "../CS316/SList.hpp"
#include "../CS316/MulPrimary.hpp"
#include "../CS316/DivPrimary.hpp"
#include "../CS316/ExprList.hpp"
#include "../CS316/ParameterList.hpp"
#include "../CS316/ArrayConstructor.hpp"
#include "../CS316/Assignment.hpp"
#include "../CS316/Term.hpp"
#include "../CS316/BoolTerm.hpp"
#include "../CS316/BoolTermOr.hpp"
#include "../CS316/BoolTermElem.hpp"
#include "../CS316/BoolPrimaryElem.hpp"
#include "../CS316/BoolPrimaryAnd.hpp"
#include "../CS316/Print.hpp"
#include "../CS316/SList.hpp"
#include "../CS316/Int.hpp"
#include "../CS316/Float.hpp"
#include "../CS316/Header.hpp"
#include "../CS316/FunDef.hpp"
#include "../CS316/FunDefList.hpp"
#include "../CS316/Parenthesized.hpp"
#include "../CS316/InvPrimary.hpp"
#include "../CS316/NegPrimary.hpp"
#include "../CS316/VarPrimary.hpp"
#include "../CS316/BoolPrimary.hpp"
#include "../CS316/BoolPrimaryCompOp.hpp"
#include "../CS316/FunCallPrimary.hpp"
#include "../CS316/ExprRightSide.hpp"
#include "../CS316/LexicalAnalyzer.hpp"
class Parser : public LexicalAnalyzer
{
public:
    
    void TestParser(const std::string& infile, const std::string& outfile);
    
    FunCallStatement* NewFunCallStatement(const std::string& id);
    
    FunCallPrimary* NewFunCallPrimary(const std::string& id);
    
    ArrayVar* NewArrayVar(const std::string& id);
    
    FunCall* NewFunCall(const std::string& id);
    
    ExprList* NewExprList();
    
    BoolTerm* NewBoolTerm();
    
    BoolPrimary* NewBoolPrimary();
    
    Expr* NewExpr(); // ⟨expr⟩ → ⟨boolTerm⟩ { || ⟨boolTerm⟩ }

    Primary* NewPrimary();
    
    Term* NewTerm(); // ⟨term⟩ → ⟨primary⟩ { (*|/) ⟨primary⟩ }
    
    E* NewE(); // <E> --> <term> { (+|-) <term> }
    
    EList* NewEList(); // ⟨E list⟩ → ⟨E⟩ { "," ⟨E⟩ }

    SList* NewSList();
    
    RightSide* NewRightSide(); // ⟨right side⟩ → ⟨array constructor⟩ | ⟨expr right side⟩
    
    Assignment* NewAssignment(Var* var); // ⟨assignment⟩ → ⟨var⟩ "=" ⟨right side⟩ ";"
    
    Var* NewVar(); // ⟨var⟩ → ⟨id var⟩ | ⟨array var⟩ | "returnVal"

    RightSide* rightSide(); // ⟨right side⟩ → ⟨array constructor⟩ | ⟨expr right side⟩

    ExprRightSide* NewExprRightSide();
    
    ArrayConstructor* NewArrayConstructor(); // ⟨array constructor⟩ → "new" "[" ⟨E list⟩ "]"
    
    Cond* NewCond(); // ⟨cond⟩ → "if" "(" ⟨expr⟩ ")" ⟨statement⟩ [ "else" ⟨statement⟩ ]
    
    While* NewWhile(); // <while> --> "while" "(" <expr> ")" <statement>
    
    Block* NewBlock(); // <block> --> "{" <s list> "}"

    bool BeginsStatement();
    
    Statement* NewStatement(); // ⟨statement⟩ → ⟨assignment⟩ | ⟨cond⟩ | ⟨while⟩ | ⟨block⟩ | ⟨fun call statement⟩ | ⟨print⟩
    
    Print* NewPrint(); // <print> --> "print" <expr> ";"
    
    Parameter* NewParameter(); // <parameter> --> <id>
    
    ParameterList* NewParameterList(); // <parameter list> --> <parameter> { "," <parameter> }
    
    Header* NewHeader(); // <header> --> <fun name> "(" [ <parameter list> ] ")"
    
    Body* NewBody(); // <body> --> "{" <s list> "}"
    
    FunDef* NewFunDef(); // <fun def> --> <header> <body>
    
    FunDefList* NewFunDefList(); // <fun def list> --> { <fun def> }+
    
    unsigned long Hash(const std::string& id);
    
    void errorMsg(int r);
    
    Parser();

    
    static HashMap<FunDef*> functmap;
    
    bool syntaxErrorFound;
};
#endif /* Parser_hpp */
