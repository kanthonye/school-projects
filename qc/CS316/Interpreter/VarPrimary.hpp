//
//  VarPrimary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef VarPrimary_hpp
#define VarPrimary_hpp
#include "../CS316/Var.hpp"
#include "../CS316/Primary.hpp"
class VarPrimary : public Primary
{
public:
    void PrintParseTree(int indent, int level);
    
    Val Eval(HashMap<Val>& state);
    VarPrimary(VarElem* var);
    ~VarPrimary();
    
    VarElem* var_elem;
};
#endif /* VarPrimary_hpp */
