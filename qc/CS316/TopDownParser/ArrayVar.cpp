//
//  ArrayVar.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "ArrayVar.hpp"

void ArrayVar::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <array var>\n", level);
    array_name.PrintParseTree(indent + SPACING, level + 1);
    elist.PrintParseTree(indent + SPACING, level + 1);
}
void ArrayVar::Parse(BufferReader& bufr)
{
    array_name.Parse(bufr);
    if (bufr != '[') throw "[error] : <array var> [ expected ";
    bufr.skip(" [\n\t\r");
    elist.Parse(bufr);
    if (bufr != ']') throw "[error] : <array var> ] expected ";
    bufr.skip(" ]\n\t\r");
}
