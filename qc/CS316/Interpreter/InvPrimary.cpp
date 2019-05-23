//
//  InvPrimary.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolVal.hpp"
#include "../CS316/InvPrimary.hpp"
void InvPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <primary>\n", level);
    PrintSpace(indent);
    IO::Write("%i  !\n", level);
    primary->PrintParseTree(indent + SPACING, level);
}

Val InvPrimary::Eval(HashMap<Val>& state)
{
    Val v = primary->Eval(state);
    if ( !v.HasVal() )
    {
        return ErrVal( "null InvPrimary" );
    }
    
    if (v->isErr())
    {
        return v;
    }
    
    if (v->IsNumeric())
    {
        return ErrVal( ("! operator cannot be applied to " + v->toString()).c_str() );
    }
    
    v->SetBool( !v->GetBool() );
    return v;
}

InvPrimary::InvPrimary(Primary* primary)
:   primary(primary)
{}

InvPrimary::~ InvPrimary()
{
    if (primary != nullptr)
    {
        delete primary;
        primary = nullptr;
    }
}
