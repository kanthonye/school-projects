//
//  ArrayName.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/ArrayName.hpp"

void ArrayName::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <array name> %s\n", level, id.c_str());
}
ArrayName::ArrayName(const std::string& id)
: id(id) {}
