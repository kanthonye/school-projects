//
//  RightSide.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "RightSide.hpp"
#include "ExprRightSide.hpp"
#include "ArrayConstructor.hpp"
void RightSide::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <right side>\n", level);
    if (right_side != nullptr)
    {
        right_side->PrintParseTree(indent+SPACING, level + 1);
    }
}
void RightSide::Parse(BufferReader& br)
{
    if (br == "new")
    {
        right_side = new ArrayConstructor;
        right_side->Parse(br);
    }
    else
    {
        right_side = new ExprRightSide;
        right_side->Parse(br);
    }
}

RightSide::~ RightSide()
{
    if (right_side != nullptr)
    {
        delete right_side;
        right_side = nullptr;
    }
}
RightSide::RightSide()
:   right_side(nullptr)
{}
