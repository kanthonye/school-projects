//
//  ID.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/23/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ID_hpp
#define ID_hpp
#include "../CS316/BaseClass.hpp"

class ID : public BaseClass
{
public:
    Val Eval(HashMap<Val>& state);
    ID(const std::string& id)
    :   id(id)
    {}
    
    std::string id;
};
#endif /* ID_hpp */
