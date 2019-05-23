//
//  BoolPrimary.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolPrimary_hpp
#define BoolPrimary_hpp
#include "../CS316/E.hpp"
#include "../CS316/Primary.hpp"
#include "../CS316/CompOp.hpp"
class BoolPrimary : public BaseClass
{   public:
public:
    virtual void PrintParseTree(int indent, int level);
    virtual Val Eval(HashMap<Val>& state, Val& val);
    virtual Val Eval(HashMap<Val>& state);
    BoolPrimary(E* e);
    ~ BoolPrimary();
    
    E* e1;
};
#endif /* BoolPrimary_hpp */
