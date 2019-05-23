//
//  VarPrimary.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/VarPrimary.hpp"
void VarPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <primary>\n", level);
    var_elem->PrintParseTree(indent + SPACING, level + 1);
}
//Val VarPrimary::Eval(HashMap<Val>& state, Val& val)
//{
//    return Eval(state);
//}
Val VarPrimary::Eval(HashMap<Val>& state)
{
    return var_elem->Eval(state);
}
VarPrimary::~VarPrimary()
{
    if (var_elem != nullptr)
    {
        delete var_elem;
        var_elem = nullptr;
    }
}

VarPrimary::VarPrimary(VarElem* var)
:   var_elem(var)
{}
