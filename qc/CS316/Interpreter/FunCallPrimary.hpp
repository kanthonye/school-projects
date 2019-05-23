//
//  FunCallPrimary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FunCallPrimary_hpp
#define FunCallPrimary_hpp
#include "../CS316/FunCall.hpp"
#include "../CS316/Primary.hpp"
class FunCallPrimary : public Primary
{
public:
    void PrintParseTree(int indent, int level);
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    FunCallPrimary(FunCall* funcall);
    ~ FunCallPrimary();
    
    FunCall* funcall;
};
#endif /* FunCallPrimary_hpp */
