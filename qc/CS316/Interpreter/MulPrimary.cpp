//
//  MulPrimary.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/24/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/MulPrimary.hpp"
void MulPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("<primary>\n");
    PrintSpace(indent+SPACING);
    IO::Write("%i *\n", level+1);
    if(primary != nullptr)
    {
        primary->PrintParseTree(indent+SPACING, level+1);
    }
}
Val MulPrimary::Eval(HashMap<Val>& state, Val& val)
{
    if (!val.HasVal())
    {
        return ErrVal("null * variable");
    }
    if ( val->isErr() )
    {
        return val;
    }
    if ( !val->IsNumeric() )
    {
        return ErrVal("* operator cannot be applied to " + val->toString());
    }
    
    Val v = primary->Eval(state);
    
    if ( !v.HasVal() )
    {
        return ErrVal("variable * null");
    }
    if ( v->isErr() )
    {
        return v;
    }
    if ( !v->IsNumeric() )
    {
        return ErrVal("* operator cannot be applied to " + v->toString());
    }
    
    if (val->isInt())
    {
        return Val( new IntVal(val->GetFloat() * v->GetFloat()) );
    }
    return Val( new FloatVal(val->GetFloat() * v->GetFloat()) );
}
MulPrimary::MulPrimary(Primary* primary)
:   PrimaryElem(primary)
{}
