//
//  Int.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Int_hpp
#define Int_hpp
#include "../CS316/Primary.hpp"
class Int : public Primary
{
public:
    void PrintParseTree(int indent, int level)
    {
        PrintSpace(indent);
        IO::Write("%i <Int> %i\n", level, digit.c_str());
    }
    
    Val Eval(HashMap<Val>& state, Val& val);
    Val Eval(HashMap<Val>& state);
    
    Int(const std::string& n)
    :   digit(n)
    ,   val(atoi(n.c_str()))
    {}
    
    std::string digit;
    int val;
};
#endif /* Int_hpp */
