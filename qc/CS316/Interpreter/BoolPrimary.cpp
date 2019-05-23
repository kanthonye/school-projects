//
//  BoolPrimary.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolPrimary.hpp"
void BoolPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <boolPrimary>\n", level);
    e1->PrintParseTree(indent +SPACING, level+1);
}

Val BoolPrimary::Eval(HashMap<Val>& state, Val& val)
{
    
    return e1->Eval(state);
}
Val BoolPrimary::Eval(HashMap<Val>& state)
{
    return e1->Eval(state);
}
BoolPrimary::BoolPrimary(E* e)
:   e1(e)
{}

BoolPrimary::~ BoolPrimary()
{
    if (e1 != nullptr)
    {
        delete e1;
        e1 = nullptr;
    }
}
