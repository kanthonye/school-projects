//
//  FunCall.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/FunDef.hpp"
#include "../CS316/Parser.hpp"
#include "../CS316/FunCall.hpp"
void FunCall::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    if (expr_list != nullptr)
    {
        IO::Write("%i <fun call>\n", level);
        fun_name->PrintParseTree(indent + SPACING, level + 1);
        expr_list->PrintParseTree(indent + SPACING, level + 1);
    }
    else
    {
        IO::Write("%i <fun call no-param>\n", level);
        fun_name->PrintParseTree(indent + SPACING, level + 1);
    }
}

void FunCall::M(HashMap<Val>& state)
{
    FunDef* func = Parser::functmap.get(fun_name->id);
    if (func == nullptr)
    {
        state.put("returnVal", ErrVal(std::string("undefined function %s") + fun_name->id));
        return;
    }
    // function with out parameters
    if (expr_list == nullptr || func->header == nullptr)
    {
        if (func->header->parameter_list == nullptr && expr_list == nullptr)
        {
            func->body->M(state);
            return;
        }
        else
        {
            state.put("returnVal", ErrVal("function call parameters don't match"));
            return;
        }
    }
    
    // function with parameters
    ParameterList* parameter_list = func->header->parameter_list;
    if (expr_list->list->size() != parameter_list->list->size())
    {
        state.put("returnVal", ErrVal("function call parameters don't match"));
        return;
    }
    
    std::string id;
    HashMap<Val> S;
    for (int i=0; i<expr_list->list->size(); i++)
    {
        Val val = expr_list->list->at(i)->Eval(state);
        if (val->isErr())
        {
            state.put("returnVal", val);
            return;
        }
        id = parameter_list->list->at(i)->id;
        S.put(id, val);
    }
    
    func->body->M(S);
    Val rval = S.get("returnVal");
    if (rval.HasVal())
    {
        state.put("returnVal", rval);
    }
}
FunCall::FunCall(FunName* fun_name, ExprList* expr_list)
:   expr_list(expr_list)
,   fun_name(fun_name)
{}

FunCall::~FunCall()
{
    if (expr_list != nullptr) {
        delete expr_list;
        expr_list = nullptr;
    }
    if (fun_name != nullptr) {
        delete fun_name;
        fun_name = nullptr;
    }
}
