//
//  FloatE.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef FloatE_hpp
#define FloatE_hpp
#include "../CS316/Float.hpp"
class FloatE : public Float
{
public:
    
    void PrintParseTree(int indent, int level);
    FloatE(const std::string& n);
};
#endif /* FloatE_hpp */
