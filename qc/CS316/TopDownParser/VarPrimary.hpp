//
//  VarPrimary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef VarPrimary_hpp
#define VarPrimary_hpp
#include "Var.hpp"
#include "Primary.hpp"
struct VarPrimary : public Primary
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    Var var;
};
#endif /* VarPrimary_hpp */
