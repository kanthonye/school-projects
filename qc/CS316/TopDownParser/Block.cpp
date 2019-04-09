//
//  Block.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Block.hpp"
void Block::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <block>\n", level);
    slist.PrintParseTree(indent + SPACING, level + 1);
}

void Block::Parse(BufferReader& br)
{
    if (br != '{') throw "[error] : <block> { expected ";
    br.skip("{ \n\t\r");
    
    slist.Parse(br);
    
    if (br != '}') throw "[error] : <block> } expected ";
    br.skip("} \n\t\r");
}
