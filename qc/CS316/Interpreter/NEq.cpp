//
//  NEq.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/1/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/NEq.hpp"
void NEq::PrintParseTree(int indent, int level)
{
    e1->PrintParseTree(indent + SPACING, level + 1);
    PrintSpace(indent);
    IO::Write("%i !=\n", level);
    e2->PrintParseTree(indent + SPACING, level + 1);
}
Val NEq::Eval(HashMap<Val>& state, Val& val)
{
    return Eval(state);
}
Val NEq::Eval(HashMap<Val>& state)
{
    Val a = e1->Eval(state);
    Val b = e2->Eval(state);
    if (a->isErr())
    {
        return a;
    }
    if (b->isErr())
    {
        return b;
    }
    
    if (a->IsNumeric() && b->IsNumeric())
    {
        return Val( new BoolVal( a->GetFloat() != b->GetFloat() ) );
    }
    if (!a->IsNumeric() && !b->IsNumeric())
    {
        return Val( new BoolVal( a->GetBool() != b->GetBool() ) );
    }
    return ErrVal("!= operator cannot be applied to [" + a->toString() + "," +  b->toString() + "]");
}
NEq::NEq(E* e1, E* e2)
:   BoolPrimaryCompOp(e1,e2)
{}
