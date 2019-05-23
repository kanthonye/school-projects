//
//  ExprList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/ExprList.hpp"
void ExprList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <expr list>\n", level);
    for (iterator i=list->begin(); i!=list->end(); i++)
    {
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}

ExprList::ExprList(std::vector<Expr*>* expr_list)
:   list(expr_list)
{}

ExprList::~ ExprList()
{
    if (list != nullptr)
    {
        for (iterator i=list->begin(); i!=list->end(); i++)
        {
            delete (*i);
        }
        delete list;
        list = nullptr;
    }
}
