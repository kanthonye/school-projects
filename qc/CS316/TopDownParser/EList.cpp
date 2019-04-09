//
//  EList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "EList.hpp"
void EList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <E list>\n", level);
    for (std::vector<E*>::iterator i=elist.begin(); i!=elist.end(); i++)
        (*i)->PrintParseTree(indent + SPACING, level + 1);
}
void EList::Parse(BufferReader& br)
{
    NewE()->Parse(br);
    while (br.equal(","))
    {
        br.skip(" ,\t\n\r");
        NewE()->Parse(br);
    }
}
