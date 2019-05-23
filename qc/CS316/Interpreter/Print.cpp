//
//  Print.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Print.hpp"
void Print::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <print>\n", level);
    expr->PrintParseTree(indent+SPACING, level + 1);
    
}

void Print::M(HashMap<Val>& state)
{
    Val v = expr->Eval(state);
    if (v.HasVal())
    {
        if (v->isErr())
        {
            IO::Error(v->toString().c_str());
        }
        else
        {
            IO::WriteLn(v->toString().c_str());
        }
    }
    else
    {
        IO::Error("null value");
    }
}
Print::Print(Expr* expr)
:   expr(expr)
{}

Print::~ Print()
{
    if (expr != nullptr)
    {
        delete expr;
        expr = nullptr;
    }
}

