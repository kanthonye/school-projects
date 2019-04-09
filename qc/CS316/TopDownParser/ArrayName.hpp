//
//  ArrayName.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayName_hpp
#define ArrayName_hpp
#include "ParseTree.hpp"
struct ArrayName : public ID
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <array name> %s\n", level, id.c_str());
    }
};
#endif /* ArrayName_hpp */
