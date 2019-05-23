//
//  ArrayConstructor.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayConstructor_hpp
#define ArrayConstructor_hpp
#include "../CS316/EList.hpp"
#include "../CS316/RightSide.hpp"
class ArrayConstructor : public RightSideElem
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    ArrayConstructor(EList* elist);
    ~ArrayConstructor();
    
    EList* elist;
};
#endif /* ArrayConstructor_hpp */
