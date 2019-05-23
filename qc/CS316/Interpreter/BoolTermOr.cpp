//
//  BoolTermOr.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/BoolTermOr.hpp"
void BoolTermOr::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i ||\n", level);
    bool_term->PrintParseTree(indent + SPACING, level + 1);
}
Val BoolTermOr::Eval(HashMap<Val>& state, Val& val)
{
    if ( val->IsNumeric() )
    {
        return ErrVal("|| operator cannot be applied to " + val->toString());
    }
    
    Val v = bool_term->Eval(state);
    
    if ( v->isErr() )
    {
        return v;
    }
    if (v->IsNumeric())
    {
        return ErrVal("|| operator cannot be applied to " + v->toString());
    }
    
    val->SetBool(v->GetBool() || val->GetBool());
    return val;
}
Val BoolTermOr::Eval(HashMap<Val>& state)
{
    return bool_term->Eval(state);
}

BoolTermOr::BoolTermOr(BoolTerm* bool_term)
:   BoolTermElem(bool_term)
{}
