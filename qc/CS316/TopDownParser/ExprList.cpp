//
//  ExprList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "ExprList.hpp"

void ExprList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <expr list>\n", level);
    for (std::vector<Expr*>::iterator i=expr_list.begin(); i!=expr_list.end(); i++)
        (*i)->PrintParseTree(indent + SPACING, level + 1);
}
void ExprList::Parse(BufferReader& br)
{
    NewExpr()->Parse(br);
    while (br.equal(","))
    {
        br.skip(", \t\n\r");
        NewExpr()->Parse(br);
    }
}

Expr* ExprList::NewExpr()
{
    Expr* e = new Expr;
    expr_list.push_back(e);
    return e;
}
