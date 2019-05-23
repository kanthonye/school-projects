//
//  Float.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Float_hpp
#define Float_hpp
#include "../CS316/Primary.hpp"
class Float : public Primary
{
public:
    
    virtual void PrintParseTree(int indent, int level);
    
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    Float(const std::string& n);
    virtual~Float(){}
    
    std::string digit;
    double val;
};

#endif /* Float_hpp */
