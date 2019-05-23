//
//  Float.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Float.hpp"
void Float::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <Float> %s\n", level, digit.c_str());
}

Val Float::Eval(HashMap<Val>& state, Val& val)
{
    return Eval(state);
}
Val Float::Eval(HashMap<Val>& state)
{
    return Val(new FloatVal(val));
}
Float::Float(const std::string& n)
:   digit(n)
,   val(atof(n.c_str()))
{}
