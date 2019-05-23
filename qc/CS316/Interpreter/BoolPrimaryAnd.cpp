//
//  BoolPrimaryAnd.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/2/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolPrimaryAnd.hpp"

void BoolPrimaryAnd::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i &&\n", level);
    bool_primary->PrintParseTree(indent + SPACING, level + 1);
}
Val BoolPrimaryAnd::Eval(HashMap<Val>& state, Val& val)
{
    if ( val->IsNumeric() )
    {
        return ErrVal("&& operator cannot be applied to " + val->toString());
    }
    
    Val v = bool_primary->Eval(state);
    
    if ( v->isErr() )
    {
        return v;
    }
    if (v->IsNumeric())
    {
        return ErrVal("&& operator cannot be applied to " + v->toString());
    }
    
    val->SetBool(v->GetBool() && val->GetBool());
    return val;
}
BoolPrimaryAnd::BoolPrimaryAnd(BoolPrimary* bp)
:   BoolPrimaryElem(bp)
{}
