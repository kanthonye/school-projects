//
//  DivPrimary.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/24/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef DivPrimary_hpp
#define DivPrimary_hpp
#include "../CS316/PrimaryElem.hpp"
class DivPrimary : public PrimaryElem
{   public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    DivPrimary(Primary* primary);
};

#endif /* DivPrimary_hpp */
