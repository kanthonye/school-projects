//
//  While.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef While_hpp
#define While_hpp
#include "Expr.hpp"
#include "Statement.hpp"
struct While : public Statement
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    Statement statement;
    Expr expr;
};
#endif /* While_hpp */
