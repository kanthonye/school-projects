//
//  Body.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp
#include "../CS316/BaseClass.hpp"
#include "../CS316/SList.hpp"
#include "../CS316/Val.hpp"
#include "../CS316/HashMap.hpp"
class Body : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    void M(HashMap<Val>& val);
    Body(SList* slist);
    ~Body();
    
    HashMap<Val*> varmap;
    SList* slist;
};
#endif /* Body_hpp */
