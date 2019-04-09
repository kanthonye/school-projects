//
//  Print.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Print.hpp"
void Print::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <print>\n", level);
    expr.PrintParseTree(indent+SPACING, level + 1);
}
void Print::Parse(BufferReader& br)
{
    if (br == "print")
    {
        br.skip("print \n\t\r");
        expr.Parse(br);
        if (br != ";")
        {
            throw "[error] : <print> ; expected";
        }
        br.skip("; \t\n\r");
    }
}

