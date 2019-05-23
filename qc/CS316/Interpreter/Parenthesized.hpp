//
//  Parenthesized.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Parenthesized_hpp
#define Parenthesized_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/Primary.hpp"
class Parenthesized : public Primary
{
public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    Parenthesized(Expr* expr);
    ~Parenthesized();
    
    Expr* expr;
};
#endif /* Parenthesized_hpp */
