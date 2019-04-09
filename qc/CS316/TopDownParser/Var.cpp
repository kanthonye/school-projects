//
//  Var.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Var.hpp"
#include "IDVar.hpp"
#include "ArrayVar.hpp"

void Var::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <var>\n", level);
    var->PrintParseTree(indent + SPACING, level + 1);
}
void Var::Parse(BufferReader& br)
{
    if (br.equal("returnVal"))
    {
        var = new ReturnVal;
        br.skip("returnVal \n\t\r");
    }
    else if (br.find("[", "-+/*=,;{}()<>&|^%$#@!~.?"))
    {
        var = new ArrayVar;
        var->Parse(br);
    }
    else
    {
        var = new IDVar;
        var->Parse(br);
    }
}
Var::~Var()
{
    if (var != nullptr)
    {
        delete var;
        var = nullptr;
    }
}
Var::Var()
:   var(nullptr)
{}
