//
//  Assignment.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Assignment_hpp
#define Assignment_hpp
#include "Var.hpp"
#include "RightSide.hpp"
#include "Statement.hpp"
struct Assignment : public Statement
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    RightSide right_side;
    Var var;
};
#endif /* Assignment_hpp */
