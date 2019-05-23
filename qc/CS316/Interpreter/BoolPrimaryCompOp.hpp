//
//  BoolPrimaryCompOp.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolPrimaryCompOp_hpp
#define BoolPrimaryCompOp_hpp
#include "../CS316/BoolPrimary.hpp"
class BoolPrimaryCompOp : public BoolPrimary
{
public:
    virtual void PrintParseTree(int indent, int level)=0;
    Val Eval(HashMap<Val>& state, Val& val) = 0;
    Val Eval(HashMap<Val>& state) = 0;
    BoolPrimaryCompOp(E* e1, E* e2);
    ~ BoolPrimaryCompOp();
    
    E* e2;
};
#endif /* BoolPrimaryCompOp_hpp */
