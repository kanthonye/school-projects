//
//  EList.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef EList_hpp
#define EList_hpp
#include "../CS316/E.hpp"
class EList : public BaseClass
{
public:
    typedef std::vector<E*>::iterator iterator;
    
    void PrintParseTree(int indent, int level);
    std::vector<E*>* GetElist(){return elist;}
    
    Val Eval(HashMap<Val>& state);
    EList(std::vector<E*>* elist);
    ~ EList();
    
    std::vector<E*>* elist;
};
#endif /* EList_hpp */
