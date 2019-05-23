//
//  FunCallStatement.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunCallStatement_hpp
#define FunCallStatement_hpp
#include "../CS316/FunCall.hpp"
#include "../CS316/Statement.hpp"
class FunCallStatement : public StatementElem
{
public:
    void PrintParseTree(int indent, int level);
    void M(HashMap<Val>& state);
    FunCallStatement(FunCall* funcall);
    ~ FunCallStatement();
    
    FunCall* funcall;
};
#endif /* FunCallStatement_hpp */
