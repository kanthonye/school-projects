//
//  Body.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp
#include "ParseTree.hpp"
#include "Slist.hpp"
struct Body : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    Slist slist;
};
#endif /* Body_hpp */
