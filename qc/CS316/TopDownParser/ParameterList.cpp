//
//  ParameterList.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "ParameterList.hpp"
void ParameterList::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <parameter list>\n", level);
    for (std::vector<Parameter*>::iterator i=parameters.begin(); i!=parameters.end(); i++)
    {
        (*i)->PrintParseTree(indent + SPACING, level + 1);
    }
}
void ParameterList::Parse(BufferReader& bufr)
{
    if (bufr != '(') throw "[error] : <parameter list> ( expected ";
    bufr.skip(" (\n\t\r");
    while (!bufr.equal(")"))
    {
        NewParameter()->Parse(bufr);
        bufr.skip(" ,\n\t\r");
    }
    if (bufr != ')') throw "[error] : <parameter list> ) expected ";
    bufr.skip(" )\n\t\r");
}
Parameter* ParameterList::NewParameter()
{
    Parameter* p = new Parameter;
    parameters.push_back(p);
    return p;
}
ParameterList::~ ParameterList()
{
    for (std::vector<Parameter*>::iterator i=parameters.begin(); i!=parameters.end(); i++)
        delete (*i);
    parameters.clear();
}
