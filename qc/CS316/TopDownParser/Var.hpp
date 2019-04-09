//
//  Var.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Var_hpp
#define Var_hpp

#include "ParseTree.hpp"
struct Var : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    ~Var();
    Var();
    
    Var* var;
};

struct ReturnVal : public Var
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <returnVal>\n", level);
    }
};
#endif /* Var_hpp */
