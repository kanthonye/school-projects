//
//  BoolTermElem.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolTermElem_hpp
#define BoolTermElem_hpp
#include "../CS316/BoolTerm.hpp"
class BoolTermElem : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    virtual Val Eval(HashMap<Val>& state, Val& val);
    virtual Val Eval(HashMap<Val>& state);
    BoolTermElem(BoolTerm* bool_term);
    ~ BoolTermElem();
    
    BoolTerm* bool_term;
};
#endif /* BoolTermElem_hpp */
