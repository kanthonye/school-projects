//
//  ArrayConstructor.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/ArrayConstructor.hpp"
void ArrayConstructor::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <array constructor>\n", level);
    elist->PrintParseTree(indent + SPACING, level + 1);
}

Val ArrayConstructor::Eval(HashMap<Val>& state)
{
    return Val();
}

ArrayConstructor::ArrayConstructor(EList* elist)
:    elist(elist)
{}

ArrayConstructor::~ArrayConstructor()
{
    if (elist == nullptr)
    {
        delete elist;
        elist = nullptr;
    }
}
