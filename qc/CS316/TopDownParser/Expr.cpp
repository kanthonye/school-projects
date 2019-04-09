//
//  Expr.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Expr.hpp"
void Expr::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <expr>\n", level);
    bool_term.PrintParseTree(indent + SPACING, level + 1);
    for (std::vector<BoolTerm*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
    {
        PrintSpace(indent + SPACING);
        printf("%i ||\n", level+1);
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}
void Expr::Parse(BufferReader& br)
{
    bool_term.Parse(br);
    while (br.equal("||"))
    {
        br.skip("|| \n\t\r");
        NewBoolTerm()->Parse(br);
    }
}
BoolTerm* Expr::NewBoolTerm()
{
    BoolTerm* b = new BoolTerm;
    booleans.push_back(b);
    return b;
}
Expr::~ Expr()
{
    for (std::vector<BoolTerm*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
        delete (*i);
    booleans.clear();
}
