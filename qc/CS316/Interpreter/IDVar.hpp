//
//  IDVar.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef IDVar_hpp
#define IDVar_hpp
#include "../CS316/VarElem.hpp"
class IDVar : public VarElem
{
public:
    virtual Val Eval(HashMap<Val>& state, Val& val);
    virtual Val Eval(HashMap<Val>& state);
    void PrintParseTree(int indent, int level);
    IDVar(const std::string& id)
    :   id(id)
    {}
    std::string id;
};
#endif /* IDVar_hpp */
