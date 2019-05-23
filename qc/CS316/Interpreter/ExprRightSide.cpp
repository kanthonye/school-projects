//
//  ExprRightSide.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/ExprRightSide.hpp"
void ExprRightSide::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <expr right side>\n", level);
    expr->PrintParseTree(indent + SPACING, level + 1);
}

Val ExprRightSide::Eval(HashMap<Val>& state)
{
    return expr->Eval(state);
}

ExprRightSide::ExprRightSide(Expr* expr)
:   expr(expr)
{}

ExprRightSide::~ExprRightSide()
{
    if (expr != nullptr)
    {
        delete expr;
        expr = nullptr;
    }
}
