//
//  TermElem.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/25/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef TermElem_hpp
#define TermElem_hpp
#include "../CS316/Term.hpp"
class TermElem : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    virtual Val Eval(HashMap<Val>& state, Val& val);
    TermElem(Term* term);
    virtual ~ TermElem();
    
    Term* term;
};
#endif /* TermElem_hpp */
