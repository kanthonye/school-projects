//
//  Body.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Body.hpp"
void Body::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <body>\n", level);
    slist.PrintParseTree(indent + SPACING, level + 1);
}

void Body::Parse(BufferReader& bufr)
{
    if (bufr != '{') throw "[error] : <body> { expected ";
    bufr.skip(" {\n\t\r");
    slist.Parse(bufr);
    if (bufr != '}') throw "[error] : <body> } expected ";
    bufr.skip(" }\n\t\r");
}
