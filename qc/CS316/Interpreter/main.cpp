//
//  main.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/3/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//
#include "CS316/Interpreter.hpp"
int main(int argc, const char * argv[])
{
    if (argc <= 2)
    {
        printf("[ERROR] : need file input\n");
        return 0;
    }
    Interpreter i(argv[1], argv[2]);
    i.Execute();
    return 0;
}
