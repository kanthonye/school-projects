
//
//  While.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/While.hpp"
void While::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <while>\n", level);
    expr->PrintParseTree(indent + SPACING, level + 1);
    statement->PrintParseTree(indent + SPACING, level + 1);
}
void While::M(HashMap<Val>& state)
{
    Val v = expr->Eval(state);
    if (v.HasVal())
    {
        if (v->isErr())
        {
            return;
        }
        
        while (v->GetBool() == true)
        {
            statement->M(state);
            v = expr->Eval(state);
            
            if (v->isErr())
            {
                IO::Error(v->toString().c_str());
                return;
            }
        }
    }
}
While::While(Expr* expr, Statement* statement)
:   statement(statement)
,   expr(expr)
{}

While::~While()
{
    if (statement != nullptr) {
        delete statement;
        statement = nullptr;
    }
    if (expr != nullptr) {
        delete expr;
        expr = nullptr;
    }
}
