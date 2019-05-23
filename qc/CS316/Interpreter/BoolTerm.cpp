//
//  BoolTerm.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolTerm.hpp"
void BoolTerm::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <boolTerm>\n", level);
    if (list->size() == 1)
    {
        for (iterator i=list->begin(); i!=list->end(); i++)
        {
            (*i)->PrintParseTree(indent + SPACING, level + 1);
        }
    }
    else
    {
        for (iterator i=list->begin(); i!=list->end(); i++)
        {
            (*i)->PrintParseTree(indent + SPACING, level + 1);
            PrintSpace(indent + SPACING);
            IO::Write("%i &&\n", level + 1);
        }
    }
}

Val BoolTerm::Eval(HashMap<Val>& state)
{
    Val val;
    for (iterator i=list->begin(); i!=list->end(); i++)
    {
        val = (*i)->Eval(state, val);
        if (val->isErr())
        {
            break;
        }
    }
    return val;
}
BoolTerm::BoolTerm(std::vector<BoolPrimaryElem*>* b)
:   list(b)
{}

BoolTerm::~ BoolTerm()
{
    if (list != nullptr)
    {
        for (iterator i=list->begin(); i!=list->end(); i++)
            delete (*i);
        
        delete list;
        list = nullptr;
    }
}
