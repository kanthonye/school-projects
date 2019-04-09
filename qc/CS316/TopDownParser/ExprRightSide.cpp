//
//  ExprRightSide.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "ExprRightSide.hpp"
void ExprRightSide::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <expr right side>\n", level);
    expr.PrintParseTree(indent + SPACING, level + 1);
}
void ExprRightSide::Parse(BufferReader& br)
{
    expr.Parse(br);
}
