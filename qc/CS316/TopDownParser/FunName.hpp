//
//  FunName.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunName_hpp
#define FunName_hpp
#include "ParseTree.hpp"
struct FunName : public ID
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <func name> %s\n", level, id.c_str());
    }
};

#endif /* FunName_hpp */
