//
//  ReturnVal.h
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ReturnVal_h
#define ReturnVal_h
#include "../CS316/IDVar.hpp"
class ReturnVal : public IDVar
{
public:
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        IO::Write("%i <returnVal>\n", level);
    }
    
    Val Eval(HashMap<Val>& state, Val& val)
    {
        state.put("returnVal", val);
        return val;
    }
    Val Eval(HashMap<Val>& state)
    {
        return state.get("returnVal");
    }
    ReturnVal()
    :   IDVar("returnVal")
    {}
};
#endif /* ReturnVal_h */
