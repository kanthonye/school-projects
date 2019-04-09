//
//  RightSide.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef RightSide_hpp
#define RightSide_hpp
#include "Expr.hpp"
#include "ParseTree.hpp"
struct RightSide : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    virtual ~ RightSide();
    RightSide();
    
    RightSide* right_side;
};
#endif /* RightSide_hpp */
