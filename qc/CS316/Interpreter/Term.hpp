//
//  Term.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Term_hpp
#define Term_hpp
#include "../CS316/PrimaryElem.hpp"
class Term : public BaseClass
{
public:
    typedef std::vector<PrimaryElem*>::iterator iterator;

    void PrintParseTree(int indent, int level);
    
    Val Eval(HashMap<Val>& state);
    Term(std::vector<PrimaryElem*>* primaries);
    virtual ~ Term();
    
    std::vector<PrimaryElem*>* list;
};
#endif /* Term_hpp */
