//
//  IDVar.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef IDVar_hpp
#define IDVar_hpp
#include "Var.hpp"
struct IDVar : public Var
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    std::string id;
};
#endif /* IDVar_hpp */
