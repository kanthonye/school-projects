//
//  Assignment.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/IDVar.hpp"
#include "../CS316/Assignment.hpp"
void Assignment::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <assignment>\n", level);
    var->PrintParseTree(indent + SPACING, level + 1);
    
    PrintSpace(indent + SPACING);
    IO::Write("%i =\n", level + 1);
    right_side->PrintParseTree(indent + SPACING, level + 1);
}

void Assignment::M(HashMap<Val>& state)
{
    Val val = right_side->Eval(state);
    if (val.HasVal())
    {
        var->Eval(state, val);
    }
}
Assignment::Assignment(Var* var, RightSide* right_side)
:   right_side(right_side)
,   var(var)
{}

Assignment::Assignment(Var* var)
:   right_side(nullptr)
,   var(nullptr)
{}
