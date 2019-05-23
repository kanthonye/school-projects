//
//  RightSide.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef RightSide_hpp
#define RightSide_hpp
#include "../CS316/Expr.hpp"
#include "../CS316/BaseClass.hpp"
class RightSideElem : public BaseClass
{
public:
    virtual Val Eval(HashMap<Val>& state) = 0;
    virtual ~ RightSideElem(){}
};

class RightSide : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    RightSide(RightSideElem* right_side);
    virtual ~ RightSide();
    
    RightSideElem* elem;
};
#endif /* RightSide_hpp */
