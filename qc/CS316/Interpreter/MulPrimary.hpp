//
//  MulPrimary.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/24/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef MulPrimary_hpp
#define MulPrimary_hpp
#include "../CS316/PrimaryElem.hpp"
class MulPrimary : public PrimaryElem
{   public:
    
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    MulPrimary(Primary* primary);
};
#endif /* MulPrimary_hpp */
