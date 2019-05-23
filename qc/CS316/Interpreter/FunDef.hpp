//
//  FunDef.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunDef_hpp
#define FunDef_hpp
#include "../CS316/Body.hpp"
#include "../CS316/Header.hpp"
#include <unordered_map>
class FunDef : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    void M(HashMap<Val>& state);
    FunDef(Header* header, Body* body);
    FunDef();
    
    Header* header;
    Body* body;
};
#endif /* FunDef_hpp */
