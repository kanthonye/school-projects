//
//  main.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/3/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//
#include <string>
#include <vector>
#include "Primary.hpp"
#include "ParseTree.hpp"
#include "Statement.hpp"
#include "FunDefList.hpp"


int main(int argc, const char * argv[])
{
    if (argc <= 1)
    {
        printf("[ERROR] : need file input\n");
        return 0;
    }
    BufferReader br;
    br.LoadText(argv[1]);

    FunDefList fdl;
    fdl.Parse(br);
    fdl.PrintParseTree(0, 0);
    
    
    return 0;
}
