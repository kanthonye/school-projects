//
//  E.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef E_hpp
#define E_hpp
#include "../CS316/TermElem.hpp"
class E : public BaseClass
{
public:
    typedef std::vector<TermElem*>::iterator iterator;
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    E(std::vector<TermElem*>* terms);
    ~ E();
    
    std::vector<TermElem*>* list;
};
#endif /* E_hpp */
