//
//  SubTerm.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef SubTerm_hpp
#define SubTerm_hpp
#include "../CS316/TermElem.hpp"
class SubTerm : public TermElem
{
public:
    
    Val Eval(HashMap<Val>& state, Val& val);
    SubTerm(Term* term);
};
#endif /* SubTerm_hpp */
