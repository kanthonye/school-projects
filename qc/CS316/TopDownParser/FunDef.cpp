//
//  FunDef.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "FunDef.hpp"
void FunDef::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <fun def>\n", level);
    header.PrintParseTree(indent + SPACING, level + 1);
    body.PrintParseTree(indent + SPACING, level + 1);
}
void FunDef::Parse(BufferReader& bufr)
{
    header.Parse(bufr);
    body.Parse(bufr);
}
