//
//  Term.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Term.hpp"
void Term::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <term>\n", level);
    for (iterator i=list->begin(); i!=list->end(); i++)
    {
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}

Val Term::Eval(HashMap<Val>& state)
{
    Val val;
    for (iterator i=list->begin(); i!=list->end(); i++)
    {
        val = (*i)->Eval(state, val);
        if (val->isErr())
        {
            return val;
        }
    }
    return val;
}

Term::Term(std::vector<PrimaryElem*>* primaries)
:   list(primaries)
{}

Term::~ Term()
{
    if (list != nullptr)
    {
        for (iterator i=list->begin(); i!=list->end(); i++)
            delete (*i);
        delete list;
        list = nullptr;
    }
}
