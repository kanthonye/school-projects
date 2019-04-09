//
//  ArrayVar.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayVar_hpp
#define ArrayVar_hpp
#include "Var.hpp"
#include "EList.hpp"
#include "ArrayName.hpp"
struct ArrayVar : public Var
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    ArrayName array_name;
    EList elist;
};
#endif /* ArrayVar_hpp */
