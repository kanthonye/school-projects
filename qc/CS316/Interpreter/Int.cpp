//
//  Int.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Int.hpp"
//
//Val Int::Eval(HashMap<Val>& state, Val& val)
//{
//    return Eval(state);
//}
Val Int::Eval(HashMap<Val>& state, Val& val)
{
    return Eval(state);
}
Val Int::Eval(HashMap<Val>& state)
{
    return Val(new IntVal(val));
}
