//
//  Header.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Header_hpp
#define Header_hpp
#include "FunName.hpp"
#include "ParameterList.hpp"
struct Header : public ParseTree
{
    void Parse(BufferReader& bufr);
    void PrintParseTree(int indent, int level);
    
    ParameterList parameter_list;
    FunName fun_name;
};
#endif /* Header_hpp */
