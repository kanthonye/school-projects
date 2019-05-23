//
//  Var.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Var.hpp"
#include "../CS316/IDVar.hpp"
#include "../CS316/ArrayVar.hpp"

void Var::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <var>\n", level);
    elem->PrintParseTree(indent + SPACING, level + 1);
}

Val Var::Eval(HashMap<Val>& state, Val& val)
{
    return elem->Eval(state, val);
}
Val Var::Eval(HashMap<Val>& state)
{
    return elem->Eval(state);
}
Var::~Var()
{
    if (elem != nullptr)
    {
        delete elem;
        elem = nullptr;
    }
}

Var::Var(VarElem* var)
:   elem(var)
{}
