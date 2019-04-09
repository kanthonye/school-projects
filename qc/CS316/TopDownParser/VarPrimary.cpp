//
//  VarPrimary.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "VarPrimary.hpp"
void VarPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <primary>\n", level);
    var.PrintParseTree(indent + SPACING, level + 1);
}
void VarPrimary::Parse(BufferReader& br)
{
    var.Parse(br);
}
