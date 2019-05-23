//
//  InvPrimary.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef InvPrimary_hpp
#define InvPrimary_hpp
#include "../CS316/Primary.hpp"
class InvPrimary : public Primary
{
public:
   
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state);
    InvPrimary(Primary* primary);
    ~ InvPrimary();
    
    Primary* primary;
};
#endif /* InvPrimary_hpp */
