//
//  ParameterList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ParameterList_hpp
#define ParameterList_hpp
#include "ParseTree.hpp"
struct Parameter : public ID
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("<parameter> %s\n", id.c_str());
    }
};

struct ParameterList : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    Parameter* NewParameter();
    ~ ParameterList();
    
    std::vector<Parameter*> parameters;
};
#endif /* ParameterList_hpp */
