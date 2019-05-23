//
//  BoolTermOr.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolTermOr_hpp
#define BoolTermOr_hpp
#include "../CS316/BoolTermElem.hpp"
class BoolTermOr : public BoolTermElem
{
public:
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    void PrintParseTree(int indent, int level);
    BoolTermOr(BoolTerm* bool_term);
};
#endif /* BoolTermOr_hpp */
