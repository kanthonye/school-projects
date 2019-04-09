//
//  E.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "E.hpp"

void PlusMinus::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i %s\n", level, value.c_str());
}
void PlusMinus::Parse(BufferReader& br)
{
    if (br.equal("-"))
    {
        br++;
        value = "-";
        br.skip(" \t\n\r");
    }
    else if (br.equal("+"))
    {
        br++;
        value = "+";
        br.skip(" \t\n\r");
    }
}


void E::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <E>\n", level);
    term.PrintParseTree(indent + SPACING, level + 1);
    for (std::vector<std::pair<PlusMinus,Term>*>::iterator i=terms.begin(); i!=terms.end(); i++)
    {
        (*i)->first.PrintParseTree(indent + SPACING, level + 1);
        (*i)->second.PrintParseTree(indent + SPACING, level + 1);
    }
}
void E::Parse(BufferReader& br)
{
    term.Parse(br);
    while (br.cequal("-+"))
    {
        std::pair<PlusMinus,Term>* pair = NewTerm();
        pair->first.Parse(br);
        pair->second.Parse(br);
        br.skip(" \t\n\r");
    }
}
