//
//  ExprList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ExprList_hpp
#define ExprList_hpp
#include "../CS316/Expr.hpp"
class ExprList : public BaseClass
{
public:
    typedef std::vector<Expr*>::iterator iterator;
    
    void PrintParseTree(int indent, int level);
    ExprList(std::vector<Expr*>* expr_list);
    ~ ExprList();
    
    std::vector<Expr*>* list;
};

#endif /* ExprList_hpp */
