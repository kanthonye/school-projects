//
//  FunDefList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "FunDefList.hpp"
void FunDefList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <fun def list>\n", level);
    for (std::vector<FunDef*>::iterator i=fundef.begin(); i!=fundef.end(); i++)
    {
        FunDef* f = *i;
        f->PrintParseTree(indent + SPACING, level + 1);
    }
}
void FunDefList::Parse(BufferReader& br)
{
    try
    {
        while (!br.empty())
        {
            br.skip(" \t\n\r");
            if (br.char_letter() || br == '_')
            {
                if (br.find("(", "-+/*=)%;{}[]&|,.!$~@#?^"))
                {
                    NewFunDef()->Parse(br);
                }
                else
                {
                    throw "[ERROR] : <fun def list> a function is expected";
                }
            }
        }
    }
    catch (const char* str)
    {
        //PrintParseTree(0, 0);
        printf("%s\n", str);
        Clear();
    }
}
FunDef* FunDefList::NewFunDef()
{
    FunDef* func = new FunDef;
    fundef.push_back(func);
    return func;
}
void FunDefList::Clear()
{
    for (std::vector<FunDef*>::iterator i=fundef.begin(); i!=fundef.end(); i++)
        delete (FunDef*)(*i);
    fundef.clear();
}
FunDefList::~ FunDefList()
{
    Clear();
}
