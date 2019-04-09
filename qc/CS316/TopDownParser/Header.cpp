//
//  Header.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Header.hpp"

void Header::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <header>\n", level);
    fun_name.PrintParseTree(indent + SPACING, level + 1);
    if (parameter_list.parameters.size() != 0)
    {
        parameter_list.PrintParseTree(indent + SPACING, level + 1);
    }
}
void Header::Parse(BufferReader& bufr)
{
    fun_name.Parse(bufr);
    parameter_list.Parse(bufr);
}
