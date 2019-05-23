//
//  ArrayVar.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/ArrayVar.hpp"
void ArrayVar::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <array var>\n", level);
    array_name->PrintParseTree(indent + SPACING, level + 1);
    elist->PrintParseTree(indent + SPACING, level + 1);
}

Val ArrayVar::Eval(HashMap<Val>& state, Val& val)
{
    return Val();
}

Val ArrayVar::Eval(HashMap<Val>& state)
{
    return Val();
}

ArrayVar::ArrayVar(ArrayName* array_name, EList* elist)
:   array_name(array_name)
,   elist(elist)
{}

ArrayVar::~ ArrayVar()
{
    if (array_name != nullptr) {
        delete array_name;
        array_name = nullptr;
    }
    if (elist != nullptr) {
        delete elist;
        elist = nullptr;
    }
}
