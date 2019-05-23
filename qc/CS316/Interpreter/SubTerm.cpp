//
//  SubTerm.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/SubTerm.hpp"

Val SubTerm::Eval(HashMap<Val>& state, Val& val)
{
    if (!val.HasVal())
    {
        return ErrVal("null - variable");
    }
    if ( val->isErr() )
    {
        return val;
    }
    if ( !val->IsNumeric() )
    {
        return ErrVal("- operator cannot be applied to " + val->toString());
    }
    
    Val v = term->Eval(state);
    
    if ( !v.HasVal() )
    {
        return ErrVal("variable - null");
    }
    if ( v->isErr() )
    {
        return v;
    }
    if ( !v->IsNumeric() )
    {
        return ErrVal("- operator cannot be applied to " + v->toString());
    }
    
    if (val->isInt())
    {
        return Val( new IntVal(val->GetFloat() - v->GetFloat()) );
    }
    return Val( new FloatVal(val->GetFloat() - v->GetFloat()) );
}
SubTerm::SubTerm(Term* term)
:   TermElem(term)
{}
