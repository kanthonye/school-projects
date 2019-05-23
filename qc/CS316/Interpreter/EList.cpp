//
//  EList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/EList.hpp"
void EList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <E list>\n", level);
    for (std::vector<E*>::iterator i=elist->begin(); i!=elist->end(); i++)
        (*i)->PrintParseTree(indent + SPACING, level + 1);
}

Val EList::Eval(HashMap<Val>& state)
{
    return Val();
}
EList::EList(std::vector<E*>* elist)
:   elist(elist)
{}

EList::~ EList()
{
    if (elist != nullptr)
    {
        for (std::vector<E*>::iterator i=elist->begin(); i!=elist->end(); i++)
            delete (*i);
        elist->clear();
        delete elist;
        elist = nullptr;
    }
}
