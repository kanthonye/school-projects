//
//  Assignment.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Assignment_hpp
#define Assignment_hpp
#include "../CS316/Var.hpp"
#include "../CS316/RightSide.hpp"
#include "../CS316/Statement.hpp"
class Assignment : public StatementElem
{
public:
    void PrintParseTree(int indent, int level);
    void M(HashMap<Val>& state);
    Assignment(Var* var, RightSide* right_side);
    Assignment(Var* var);
    
    RightSide* right_side;
    Var* var;
};
#endif /* Assignment_hpp */
