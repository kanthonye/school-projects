//
//  While.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef While_hpp
#define While_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/Statement.hpp"
class While : public StatementElem
{
public:
    void PrintParseTree(int indent, int level);
    void M(HashMap<Val>& state);
    While(Expr* expr, Statement* statement);
    ~While();
    
    Statement* statement;
    Expr* expr;
};
#endif /* While_hpp */
