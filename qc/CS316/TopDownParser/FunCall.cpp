//
//  FunCall.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "FunCall.hpp"
void FunCall::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <fun call>\n", level);
    fun_name.PrintParseTree(indent + SPACING, level + 1);
    expr_list.PrintParseTree(indent + SPACING, level + 1);
}
void FunCall::Parse(BufferReader& br)
{
    fun_name.Parse(br);
    if (!br.cequal("(")) throw "[error] : <fun call> ( expected.";
    br.skip("( \n\t\r");
    
    expr_list.Parse(br);
    if (!br.cequal(")")) throw "[error] : <fun call> ) expected.";
    br.skip(") \n\t\r");
}
