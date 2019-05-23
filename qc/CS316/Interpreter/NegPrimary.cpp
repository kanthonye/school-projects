//
//  NegPrimary.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/NegPrimary.hpp"
void NegPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write(" <neg>\n");
    
    primary->PrintParseTree(indent+SPACING, level+1);
}
//Val NegPrimary::Eval(HashMap<Val>& state, Val& val)
//{
//    return Eval(state);
//}
Val NegPrimary::Eval(HashMap<Val>& state)
{
    Val v = primary->Eval(state);
    if ( v.HasVal() )
    {
        if (v->IsNumeric())
        {
            v->SetInt( -v->GetInt() );
        }
        else
        {
            return ErrVal( ("unary - operator cannot be applied to " + v->toString()).c_str() );
        }
    }
    return v;
}
NegPrimary::NegPrimary(Primary* primary)
:   primary(primary)
{}
NegPrimary::~ NegPrimary()
{
    if (primary != nullptr)
    {
        delete primary;
        primary = nullptr;
    }
}
