
//
//  Cond.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Cond.hpp"
void Cond::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <cond>\n", level);
    PrintSpace(indent + SPACING);
    printf("%i if\n",level + 1);
    if_expr.PrintParseTree(indent + SPACING, level + 1);
    if_statement.PrintParseTree(indent + SPACING, level + 1);
    if (else_statement.statement != nullptr)
    {
        else_statement.PrintParseTree(indent + SPACING, level + 1);
    }
}
void Cond::Parse(BufferReader& br)
{
    br.skip("if \t\n\r");
    if (br.cequal("("))
    {
        br.skip("( \t\n\r");
        if_expr.Parse(br);
        if (!br.cequal(")"))
        {
            throw "[error] : <cond> ) expected";
        }
        br.skip(") \t\n\r");
        if_statement.Parse(br);
        if (br.equal("else"))
        {
            br.skip("else \t\n\r");
            else_statement.Parse(br);
        }
    }
    else
    {
        throw "[error] <cond> ( expected";
    }
}
Cond::~ Cond()
{
}
Cond::Cond()
{}
