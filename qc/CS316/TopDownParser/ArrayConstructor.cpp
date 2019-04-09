//
//  ArrayConstructor.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "ArrayConstructor.hpp"
void ArrayConstructor::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <array constructor>\n", level);
    elist.PrintParseTree(indent + SPACING, level + 1);
}
void ArrayConstructor::Parse(BufferReader& br)
{
    if (br != "new") throw "[error] : <array constructor> 'new' expected";
    br.skip("new \t\n\r");
    if (br != "[") throw "[error] : <array constructor> '[' expected";
    br.skip("[ \n\t\r");
    elist.Parse(br);
    if (br != "]") throw "[error] : <array constructor> ']' expected";
    br.skip("] \n\t\r");
}
