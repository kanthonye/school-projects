//
//  FunDef.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunDef_hpp
#define FunDef_hpp
#include "Body.hpp"
#include "Header.hpp"
struct FunDef : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& bufr);
    
    Header header;
    Body body;
};
#endif /* FunDef_hpp */
