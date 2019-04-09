//
//  FunCall.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunCall_hpp
#define FunCall_hpp
#include "FunName.hpp"
#include "ExprList.hpp"
struct FunCall : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    ExprList expr_list;
    FunName fun_name;
};
#endif /* FunCall_hpp */
