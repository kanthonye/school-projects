//
//  BoolTerm.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolTerm_hpp
#define BoolTerm_hpp
#include "../CS316/BoolPrimaryElem.hpp"
class BoolTerm : public BaseClass
{
public:
    typedef std::vector<BoolPrimaryElem*>::iterator iterator;
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    BoolTerm(std::vector<BoolPrimaryElem*>* list);
    ~ BoolTerm();
    
    std::vector<BoolPrimaryElem*>* list;
};
#endif /* BoolTerm_hpp */
