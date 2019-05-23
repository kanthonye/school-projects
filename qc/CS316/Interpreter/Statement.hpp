//
//  Statement.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Statement_hpp
#define Statement_hpp
#include "../CS316/BaseClass.hpp"

class StatementElem : public BaseClass
{public:
    virtual void M(HashMap<Val>& state) = 0;
    virtual ~ StatementElem(){}
};

class Statement : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    
    void M(HashMap<Val>& state);
    Statement(StatementElem* statement);
    virtual ~ Statement();
    
    StatementElem* elem;
};
#endif /* Statement_hpp */
