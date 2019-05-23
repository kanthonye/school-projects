//
//  E.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/E.hpp"
void E::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <E>\n", level);
    for (iterator i=list->begin(); i!=list->end(); i++)
    {
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}
Val E::Eval(HashMap<Val>& state)
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
E::E(std::vector<TermElem*>* terms)
:   list(terms)
{}

E::~ E()
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
