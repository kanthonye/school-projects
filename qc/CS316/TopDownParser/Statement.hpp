//
//  Statement.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Statement_hpp
#define Statement_hpp
#include "ParseTree.hpp"
struct Statement : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    virtual ~ Statement();
    Statement();
    
    Statement* statement;
};
#endif /* Statement_hpp */
