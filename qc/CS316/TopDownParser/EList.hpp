//
//  EList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef EList_hpp
#define EList_hpp
#include "E.hpp"
struct EList : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    E* NewE()
    {
        E* e = new E;
        elist.push_back(e);
        return e;
    }
    ~ EList()
    {
        for (std::vector<E*>::iterator i=elist.begin(); i!=elist.end(); i++)
            delete (*i);
        elist.clear();
    }
    
    std::vector<E*> elist;
};
#endif /* EList_hpp */
