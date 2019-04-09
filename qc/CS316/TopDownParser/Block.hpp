//
//  Block.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp
#include "Statement.hpp"
#include "Slist.hpp"
struct Block : public Statement
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    Slist slist;
};
#endif /* Block_hpp */
