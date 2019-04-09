//
//  Primary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Primary_hpp
#define Primary_hpp
#include "ParseTree.hpp"

struct Primary : public ParseTree
{
    virtual void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    virtual ~ Primary();
    Primary(): primary(nullptr) {}
    
    Primary* primary;
    std::string preval;
};

struct Int : public Primary
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <primary> %s\n", level, numeric.c_str());
    }
    Int(const char* n) : numeric(n) {}
    std::string numeric;
};

struct Float : public Primary
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <primary> %s\n", level, numeric.c_str());
    }
    Float(const char* n) : numeric(n) {}
    std::string numeric;
};

struct FloatE : public Primary
{
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        printf("%i <primary> %s\n", level, numeric.c_str());
    }
    FloatE(const char* n) : numeric(n) {}
    std::string numeric;
};

#endif /* Primary_hpp */
