//
//  BoolTerm.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "BoolTerm.hpp"


void CompOp::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i %s\n",level, op.c_str());
}
void CompOp::Parse(BufferReader& br)
{
    if (br.cequal("<="))
    {
        br.skip("<=");
        op = "<=";
    }
    else if (br.cequal(">="))
    {
        br.skip(">=");
        op = ">=";
    }
    else if (br.cequal(">"))
    {
        br.skip(">");
        op = ">";
    }
    else if (br.cequal("<"))
    {
        br.skip("<");
        op = "<";
    }
    else if (br.cequal("=="))
    {
        br.skip("==");
        op = "==";
    }
    else if (br.cequal("!="))
    {
        br.skip("!=");
        op = "!=";
    }
    else
    {
        throw "[error] : unknown boolean expression";
    }
    br.skip(" \t\n\r");
}


void BoolPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <boolPrimary>\n", level);
    e.PrintParseTree(indent + SPACING, level + 1);
    for (std::vector<std::pair<CompOp, E>*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
    {
        (*i)->first.PrintParseTree(indent + SPACING, level + 1);
        (*i)->second.PrintParseTree(indent + SPACING, level + 1);
    }
}
void BoolPrimary::Parse(BufferReader& br)
{
    e.Parse(br);
    while (br.equal("<=") || br.equal(">=") || br.equal(">") || br.equal("<") || br.equal("==") || br.equal("!="))
    {
        std::pair<CompOp, E>* pair = NewCompE();
        pair->first.Parse(br);
        pair->second.Parse(br);
        br.skip(" \n\t\r");
    }
}
std::pair<CompOp, E>* BoolPrimary::NewCompE()
{
    std::pair<CompOp, E>* p = new std::pair<CompOp, E>;
    booleans.push_back(p);
    return p;
}
BoolPrimary::~ BoolPrimary()
{
    for (std::vector<std::pair<CompOp, E>*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
        delete (*i);
    booleans.clear();
}




void BoolTerm::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <boolTerm>\n", level);
    bool_primary.PrintParseTree(indent + SPACING, level + 1);
    for (std::vector<BoolPrimary*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
    {
        PrintSpace(indent + SPACING);
        printf("%i &&\n", level+1);
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}
void BoolTerm::Parse(BufferReader& br)
{
    bool_primary.Parse(br);
    while (br.equal("&&"))
    {
        br.skip("&& \n\t\r");
        NewBoolPrimary()->Parse(br);
    }
}
BoolPrimary* BoolTerm::NewBoolPrimary()
{
    BoolPrimary* b = new BoolPrimary;
    booleans.push_back(b);
    return b;
}
BoolTerm::~ BoolTerm()
{
    for (std::vector<BoolPrimary*>::iterator i=booleans.begin(); i!=booleans.end(); i++)
        delete (*i);
    booleans.clear();
}
