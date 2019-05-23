//
//  FunCallPrimary.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/FunDef.hpp"
#include "../CS316/Parser.hpp"
#include "../CS316/FunCallPrimary.hpp"
void FunCallPrimary::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <fun call primary>\n", level);
    funcall->PrintParseTree(indent, level + 1);
}

//Val FunCallPrimary::Eval(HashMap<Val>& state, Val& val)
//{
//    return funcall->Eval(state);
//}

Val FunCallPrimary::Eval(HashMap<Val>& state)
{
    funcall->M(state);
    return state.get("returnVal");
}

FunCallPrimary::FunCallPrimary(FunCall* funcall)
:   funcall(funcall)
{}

FunCallPrimary::~ FunCallPrimary()
{
    if (funcall == nullptr)
    {
        delete funcall;
        funcall = nullptr;
    }
}
