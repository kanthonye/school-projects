//
//  Cond.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Cond_hpp
#define Cond_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/Statement.hpp"
class Cond : public StatementElem
{
public:
    virtual void M(HashMap<Val>& state) = 0;
    virtual ~ Cond(){}
};
#endif /* Cond_hpp */
