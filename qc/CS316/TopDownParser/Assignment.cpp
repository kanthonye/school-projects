//
//  Assignment.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Assignment.hpp"
void Assignment::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <assignment>\n", level);
    var.PrintParseTree(indent + SPACING, level + 1);
    
    PrintSpace(indent + SPACING);
    printf("%i =\n", level + 1);
    right_side.PrintParseTree(indent + SPACING, level + 1);
}
void Assignment::Parse(BufferReader& br)
{
    var.Parse(br);
    if (br != '=')
    {
        throw "[error] : <assignment> = expected";
    }
    br.skip("= \t\n\r");
    right_side.Parse(br);
    if (br != ';')
    {
        throw "[error] : <assignment> ; expected";
    }
    br.skip("; \t\n\r");
}
