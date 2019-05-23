//
//  Block.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Block.hpp"
void Block::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <block>\n", level);
    slist->PrintParseTree(indent + SPACING, level + 1);
}

void Block::M(HashMap<Val>& state)
{
    slist->M(state);
}
Block::Block(SList* slist)
:   slist(slist)
{}

Block::~Block()
{
    if (slist != nullptr)
    {
        delete slist;
        slist = nullptr;
    }
}
