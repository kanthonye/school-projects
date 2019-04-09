//
//  ExprRightSide.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ExprRightSide_hpp
#define ExprRightSide_hpp
#include "Expr.hpp"
#include "RightSide.hpp"
struct ExprRightSide : public RightSide
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    Expr expr;
};
#endif /* ExprRightSide_hpp */
