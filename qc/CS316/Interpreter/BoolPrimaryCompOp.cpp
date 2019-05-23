//
//  BoolPrimaryCompOp.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolPrimaryCompOp.hpp"
void BoolPrimaryCompOp::PrintParseTree(int indent, int level){}

BoolPrimaryCompOp::BoolPrimaryCompOp(E* e1, E* e2)
:   BoolPrimary(e1)
,   e2(e2)
{}

BoolPrimaryCompOp::~ BoolPrimaryCompOp()
{
    if (e2 != nullptr)
    {
        delete e2;
        e2 = nullptr;
    }
}
