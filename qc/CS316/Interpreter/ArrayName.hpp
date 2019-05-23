//
//  ArrayName.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef ArrayName_hpp
#define ArrayName_hpp
#include "../CS316/ID.hpp"
class ArrayName : public BaseClass
{
public:
    void PrintParseTree(int indent, int level);
    ArrayName(const std::string& id);

    std::string id;
};
#endif /* ArrayName_hpp */
