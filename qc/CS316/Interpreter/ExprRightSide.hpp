//
//  ExprRightSide.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ExprRightSide_hpp
#define ExprRightSide_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/RightSide.hpp"
class ExprRightSide : public RightSideElem
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    ExprRightSide(Expr* expr);
    ~ExprRightSide();
    
    Expr* expr;
};
#endif /* ExprRightSide_hpp */
