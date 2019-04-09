//
//  BoolTerm.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BoolTerm_hpp
#define BoolTerm_hpp
#include "E.hpp"
#include "Primary.hpp"

struct CompOp : public Primary
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    std::string op;
};

struct BoolPrimary : public Primary
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    std::pair<CompOp, E>* NewCompE();
    ~ BoolPrimary();
    
    std::vector<std::pair<CompOp, E>*> booleans;
    E e;
};

struct BoolTerm : public Primary
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    BoolPrimary* NewBoolPrimary();
    ~ BoolTerm();
    
    std::vector<BoolPrimary*> booleans;
    BoolPrimary bool_primary;
};
#endif /* BoolTerm_hpp */
