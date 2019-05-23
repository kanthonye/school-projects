//
//  BoolPrimaryElem.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/2/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolPrimaryElem.hpp"

void BoolPrimaryElem::PrintParseTree(int indent, int level)
{
    bool_primary->PrintParseTree(indent, level);
}
Val BoolPrimaryElem::Eval(HashMap<Val>& state, Val& val)
{
    return bool_primary->Eval(state);
}
Val BoolPrimaryElem::Eval(HashMap<Val>& state)
{
    return bool_primary->Eval(state);
}

BoolPrimaryElem::BoolPrimaryElem(BoolPrimary* bp)
:   bool_primary(bp)
{}
