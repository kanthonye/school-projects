//
//  ExprList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ExprList_hpp
#define ExprList_hpp
#include "Expr.hpp"
struct ExprList : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    Expr* NewExpr();
    ~ ExprList()
    {
        for (std::vector<Expr*>::iterator i=expr_list.begin(); i!=expr_list.end(); i++)
            delete (*i);
        expr_list.clear();
    }
    
    std::vector<Expr*> expr_list;
};

#endif /* ExprList_hpp */
