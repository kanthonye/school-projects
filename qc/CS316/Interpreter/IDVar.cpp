//
//  IDVar.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/IDVar.hpp"
Val IDVar::Eval(HashMap<Val>& state, Val& val)
{
    state.put(id, val);
    return val;
}
Val IDVar::Eval(HashMap<Val>& state)
{
    Val val = state.get(id);
    if (!val.HasVal())
    {
        return ErrVal("variable " + id + " does not have a value");
    }
    return val;
}
void IDVar::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <id var> %s\n", level, id.c_str());
}
