//
//  BoolPrimaryElem.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 5/2/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolPrimaryElem_hpp
#define BoolPrimaryElem_hpp
#include "../CS316/BoolPrimary.hpp"
class BoolPrimaryElem : public BaseClass
{
public:
    virtual void PrintParseTree(int indent, int level);
    virtual Val Eval(HashMap<Val>& state, Val& val);
    virtual Val Eval(HashMap<Val>& state);
    BoolPrimaryElem(BoolPrimary* bp);
    
    BoolPrimary* bool_primary;
};
#endif /* BoolPrimaryElem_hpp */
