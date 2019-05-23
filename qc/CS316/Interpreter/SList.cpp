//
//  Slist.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//
#include "../CS316/Cond.hpp"
#include "../CS316/SList.hpp"
#include "../CS316/IDVar.hpp"
#include "../CS316/Block.hpp"
#include "../CS316/Print.hpp"
#include "../CS316/While.hpp"
#include "../CS316/ReturnVal.hpp"
#include "../CS316/ArrayVar.hpp"
#include "../CS316/FunCallStatement.hpp"
void SList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <s list>\n", level);
    for (SList::iterator s=list->begin(); s!=list->end(); s++)
        (*s)->PrintParseTree(indent + SPACING, level + 1);
}

void SList::M(HashMap<Val>& state)
{
    for (SList::iterator s=list->begin(); s!=list->end(); s++)
    {
        (*s)->M(state);
    }
}
SList::SList(std::vector<Statement*>* slist)
:   list(slist)
{}

SList::~ SList()
{
    if (list != nullptr)
    {
        for (SList::iterator s=list->begin(); s!=list->end(); s++)
            delete (*s);
        delete list;
        list = nullptr;
    }
}
