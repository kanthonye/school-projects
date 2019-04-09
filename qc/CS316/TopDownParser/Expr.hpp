//
//  Expr.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Expr_hpp
#define Expr_hpp
#include "BoolTerm.hpp"
#include "Primary.hpp"
struct Expr : public Primary
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    BoolTerm* NewBoolTerm();
    ~ Expr();
    
    std::vector<BoolTerm*> booleans;
    BoolTerm bool_term;
};
#endif /* Expr_hpp */
