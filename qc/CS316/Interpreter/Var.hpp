//
//  Var.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Var_hpp
#define Var_hpp
#include "../CS316/VarElem.hpp"
class Var : public BaseClass
{
public:
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    void PrintParseTree(int indent, int level);
    Var(VarElem* var);
    ~Var();
    
    VarElem* elem;
};
#endif /* Var_hpp */
