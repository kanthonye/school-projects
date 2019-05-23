//
//  Body.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Body.hpp"
void Body::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <body>\n", level);
    slist->PrintParseTree(indent + SPACING, level + 1);
}

void Body::M(HashMap<Val>& state)
{
    slist->M(state);
}
Body::Body(SList* slist)
:   slist(slist)
{}

Body::~Body()
{
    if (slist != nullptr)
    {
        delete slist;
        slist = nullptr;
    }
}
