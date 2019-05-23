//
//  BoolPrimaryAnd.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/2/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolPrimaryAnd_hpp
#define BoolPrimaryAnd_hpp
#include "../CS316/BoolPrimaryElem.hpp"
class BoolPrimaryAnd : public BoolPrimaryElem
{
public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    BoolPrimaryAnd(BoolPrimary* bp);
};
#endif /* BoolPrimaryAnd_hpp */
