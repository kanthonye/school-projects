//
//  Slist.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Slist_hpp
#define Slist_hpp
#include "Statement.hpp"
struct Slist : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    Statement* NewStatement();
    ~ Slist();
    
    std::vector<Statement*> statements;
};
#endif /* Slist_hpp */
