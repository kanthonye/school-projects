//
//  ParseTree.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ParseTree_hpp
#define ParseTree_hpp
#include <string>
#include <vector>
#include "BufferReader.hpp"

#define SPACING 2
#define WHITE_SPACE " \t\n\r"
#define NUMERIC(n) ((n >= '0' && n <= '9') || (n == '-' || n == '+' || n == '.'))
#define IS_ID(n) ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z') || (n == '_'))
struct ParseTree
{
    virtual void PrintParseTree(int indent, int level){}
    virtual void Parse(BufferReader& br){}
    
    void PrintSpace(int indent)
    {
        for (int i=0; i<indent; i++) printf(" ");
    }
};


struct ID : public ParseTree
{
    void Parse(BufferReader& br)
    {
        long i = 0;
        char name[64];
        while (br.char_letter() || br.equal("_"))
        {
            while (br == "_") name[i++] = '_';
            i += br.read_letters(&name[i], 64);
            while (br == "_") name[i++] = '_';
            i += br.read_digits(&name[i], 64);
            while (br == "_") name[i++] = '_';
        }
        br.skip(" \t\n\r");
        id = name;
    }
    std::string id;
};
#endif /* ParseTree_hpp */
