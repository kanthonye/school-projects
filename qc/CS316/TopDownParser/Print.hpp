//
//  Print.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Print_hpp
#define Print_hpp
#include "Expr.hpp"
#include "Statement.hpp"
struct Print : public Statement
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    Expr expr;
};
#endif /* Print_hpp */
