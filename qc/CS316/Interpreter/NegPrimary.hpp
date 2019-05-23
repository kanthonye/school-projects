//
//  NegPrimary.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef NegPrimary_hpp
#define NegPrimary_hpp
#include "../CS316/Primary.hpp"
class NegPrimary : public Primary
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    NegPrimary(Primary* primary);
    ~ NegPrimary();
    
    Primary* primary;
};
#endif /* NegPrimary_hpp */
