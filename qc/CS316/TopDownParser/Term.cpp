//
//  Term.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Term.hpp"
void MulDiv::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i %s\n", level, value.c_str());
}
void MulDiv::Parse(BufferReader& br)
{
    if (br.equal("*"))
    {
        value = "*";
        br.skip("* \t\n\r");
    }
    else if (br.equal("/"))
    {
        value = "/";
        br.skip("/ \t\n\r");
    }
}


void Term::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <term>\n", level);
    primary.PrintParseTree(indent + SPACING, level + 1);
    for (std::vector<std::pair<MulDiv, Primary>*>::iterator i=primaries.begin(); i!=primaries.end(); i++)
    {
        (*i)->first.PrintParseTree(indent + SPACING, level + 1);
        (*i)->second.PrintParseTree(indent + SPACING, level + 1);
    }
}
void Term::Parse(BufferReader& br)
{
    primary.Parse(br);
    while (br.cequal("*/"))
    {
        std::pair<MulDiv, Primary>* p = NewPrimary();
        p->first.Parse(br);
        p->second.Parse(br);
        br.skip(" \t\n\r");
    }
}
std::pair<MulDiv, Primary>* Term::NewPrimary()
{
    std::pair<MulDiv, Primary>* p = new std::pair<MulDiv, Primary>;
    primaries.push_back(p);
    return p;
}
Term::~ Term()
{
    for (std::vector<std::pair<MulDiv, Primary>*>::iterator i=primaries.begin(); i!=primaries.end(); i++)
        delete (*i);
    primaries.clear();
    }
