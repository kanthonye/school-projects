//
//  Term.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Term_hpp
#define Term_hpp
#include "Primary.hpp"
struct MulDiv : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    std::string value;
};

struct Term : public ParseTree
{
    std::pair<MulDiv, Primary>* NewPrimary();
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    ~ Term();
    
    std::vector<std::pair<MulDiv, Primary>*> primaries;
    Primary primary;
};
#endif /* Term_hpp */
