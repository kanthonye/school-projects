//
//  E.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef E_hpp
#define E_hpp
#include "Term.hpp"

struct PlusMinus : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    std::string value;
};


struct E : public ParseTree
{
    void PrintParseTree(int indent, int level);
    void Parse(BufferReader& br);
    
    std::pair<PlusMinus,Term>* NewTerm()
    {
        std::pair<PlusMinus,Term>* t = new std::pair<PlusMinus,Term>;
        terms.push_back(t);
        return t;
    }
    ~ E()
    {
        for (std::vector<std::pair<PlusMinus,Term>*>::iterator i=terms.begin(); i!=terms.end(); i++)
            delete (*i);
        terms.clear();
    }
    
    std::vector<std::pair<PlusMinus,Term>*> terms;
    Term term;
};
#endif /* E_hpp */
