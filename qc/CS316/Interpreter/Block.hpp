//
//  Block.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp
#include "../CS316/Statement.hpp"
#include "../CS316/SList.hpp"
class Block : public StatementElem
{
public:
    void M(HashMap<Val>& state);
    void PrintParseTree(int indent, int level);
    Block(SList* slist);
    ~Block();
    
    SList* slist;
};
#endif /* Block_hpp */
