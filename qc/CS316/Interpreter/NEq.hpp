//
//  NEq.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/1/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef NEq_hpp
#define NEq_hpp
#include "../CS316/BoolPrimaryCompOp.hpp"
class NEq : public BoolPrimaryCompOp
{
public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    NEq(E* e1, E* e2);
};
#endif /* NEq_hpp */
