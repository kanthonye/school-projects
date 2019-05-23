//
//  ID.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/HashMap.hpp"
#include "../CS316/ID.hpp"

Val ID::Eval(HashMap<Val>& state)
{
    Val val = state.get(id);
    if ( !val.HasVal() )
    {
        return ErrVal(id + " does not have a value");
    }
    return val;
}
