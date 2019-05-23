//
//  LE.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/1/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef LE_hpp
#define LE_hpp
#include "../CS316/BoolPrimaryCompOp.hpp"
class LE : public BoolPrimaryCompOp
{
public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    LE(E* e1, E* e2);
};
#endif /* LE_hpp */
