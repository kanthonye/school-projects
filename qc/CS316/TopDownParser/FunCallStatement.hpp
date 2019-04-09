//
//  FunCallStatement.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunCallStatement_hpp
#define FunCallStatement_hpp
#include "FunCall.hpp"
#include "Statement.hpp"
struct FunCallStatement : public Statement
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <fun call statement>\n", level);
        funcal.PrintParseTree(indent + SPACING, level + 1);
    }
    void Parse(BufferReader& br)
    {
        funcal.Parse(br);
        if (!br.cequal(";")) throw "[error] : <fun call statement> ; expected.";
        br.skip("; \n\t\r");
    }
    FunCall funcal;
};
#endif /* FunCallStatement_hpp */
