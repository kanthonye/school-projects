//
//  Primary.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Primary_hpp
#define Primary_hpp
#include "../CS316/BaseClass.hpp"
class Primary : public BaseClass
{
public:
    virtual Val Eval(HashMap<Val>& state) = 0;
    virtual ~ Primary(){}
};
#endif /* Primary_hpp */
