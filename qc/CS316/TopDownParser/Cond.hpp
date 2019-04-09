//
//  Cond.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Cond_hpp
#define Cond_hpp
#include "Expr.hpp"
#include "Statement.hpp"

struct CondElse : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    Statement statement;
};

struct Cond : public Statement
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    ~ Cond();
    Cond();
    
    Statement else_statement;
    Statement if_statement;
    Expr if_expr;
};
#endif /* Cond_hpp */
