//
//  IDVar.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "IDVar.hpp"

void IDVar::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <id var> %s\n", level, id.c_str());
}
void IDVar::Parse(BufferReader& br)
{
    long i = 0;
    char name[64];
    while (br.char_letter() || br.equal("_"))
    {
        while (br == "_") name[i++] = '_';
        i += br.read_letters(&name[i], 64);
        while (br == "_") name[i++] = '_';
        i += br.read_digits(&name[i], 64);
        while (br == "_") name[i++] = '_';
    }
    br.skip(" \t\n\r");
    id = name;
}
