//
//  RightSide.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/RightSide.hpp"
#include "../CS316/ExprRightSide.hpp"
#include "../CS316/ArrayConstructor.hpp"
void RightSide::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <right side>\n", level);
    if (elem != nullptr)
    {
        elem->PrintParseTree(indent+SPACING, level + 1);
    }
}

Val RightSide::Eval(HashMap<Val>& state)
{
    return elem->Eval(state);
}

RightSide::RightSide(RightSideElem* right_side)
:   elem(right_side)
{}

RightSide::~ RightSide()
{
    if (elem != nullptr)
    {
        delete elem;
        elem = nullptr;
    }
}
