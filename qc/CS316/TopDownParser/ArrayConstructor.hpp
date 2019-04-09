//
//  ArrayConstructor.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayConstructor_hpp
#define ArrayConstructor_hpp
#include "EList.hpp"
#include "RightSide.hpp"
struct ArrayConstructor : public RightSide
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    EList elist;
};
#endif /* ArrayConstructor_hpp */
