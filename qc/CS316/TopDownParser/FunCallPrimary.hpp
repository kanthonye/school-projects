//
//  FunCallPrimary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunCallPrimary_hpp
#define FunCallPrimary_hpp
#include "FunCall.hpp"
#include "Primary.hpp"
struct FunCallPrimary : public Primary
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <fun call primary>\n", level);
        funcall.PrintParseTree(indent, level + 1);
    }
    void Parse(BufferReader& bufr)
    {
        funcall.Parse(bufr);
    }
    FunCall funcall;
};
#endif /* FunCallPrimary_hpp */
