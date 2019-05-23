//
//  Print.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Print_hpp
#define Print_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/Statement.hpp"
class Print : public StatementElem
{
public:
    void M(HashMap<Val>& state);
    void PrintParseTree(int indent, int level);
    Print(Expr* expr);
    ~Print();
    
    Expr* expr;
};
#endif /* Print_hpp */
