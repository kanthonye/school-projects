//
//  ArrayVar.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayVar_hpp
#define ArrayVar_hpp
#include "../CS316/VarElem.hpp"
#include "../CS316/EList.hpp"
#include "../CS316/ArrayName.hpp"
class ArrayVar : public VarElem
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    ArrayVar(ArrayName* array_name, EList* elist);
    ~ArrayVar();
    
    ArrayName* array_name;
    EList* elist;
};
#endif /* ArrayVar_hpp */
