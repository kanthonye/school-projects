//
//  FunDefList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunDefList_hpp
#define FunDefList_hpp
#include "FunDef.hpp"
struct FunDefList : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    void Clear();
    FunDef* NewFunDef();
    ~ FunDefList();
    
    std::vector<FunDef*> fundef;
};
#endif /* FunDefList_hpp */
