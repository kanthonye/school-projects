//
//  Slist.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Slist.hpp"
void Slist::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <s list>\n", level);
    for (std::vector<Statement*>::iterator i=statements.begin(); i!=statements.end(); i++)
        (*i)->PrintParseTree(indent + SPACING, level + 1);
}
void Slist::Parse(BufferReader& br)
{
    while (!br.cequal("{}[]"))
    {
        NewStatement()->Parse(br);
        if (br == ';')
        {
            br.skip("; \n\t\r");
        }
    }
}

Statement* Slist::NewStatement()
{
    Statement* s = new Statement;
    statements.push_back(s);
    return s;
}
Slist::~ Slist()
{
    for (std::vector<Statement*>::iterator i=statements.begin(); i!=statements.end(); i++)
        delete (*i);
    statements.clear();
    }
