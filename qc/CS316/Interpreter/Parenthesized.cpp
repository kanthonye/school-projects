//
//  Parenthesized.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Parenthesized.hpp"
void Parenthesized::PrintParseTree(int indent, int level)
{
    expr->PrintParseTree(indent, level);
}
//Val Parenthesized::Eval(HashMap<Val>& state, const Val& val)
//{
//    return expr->Eval(state);
//}
Val Parenthesized::Eval(HashMap<Val>& state)
{
    return expr->Eval(state);
}
Parenthesized::Parenthesized(Expr* expr)
:   expr(expr)
{}
Parenthesized::~ Parenthesized()
{
    if (expr)
    {
        delete expr;
        expr = nullptr;
    }
}
