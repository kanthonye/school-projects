//
//  AddTerm.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef AddTerm_hpp
#define AddTerm_hpp
#include "../CS316/TermElem.hpp"
class AddTerm : public TermElem
{
public:
    
    Val Eval(HashMap<Val>& state, Val& val);
    AddTerm(Term* term);
};
#endif /* AddTerm_hpp */
