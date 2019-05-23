//
//  Slist.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef SList_hpp
#define SList_hpp
#include "../CS316/Statement.hpp"
class SList : public BaseClass
{
public:
    typedef std::vector<Statement*>::iterator iterator;
    
    void PrintParseTree(int indent, int level);
    
    void M(HashMap<Val>& state);
    SList(std::vector<Statement*>* statements);
    ~ SList();
    
    std::vector<Statement*>* list;
};
#endif /* Slist_hpp */
