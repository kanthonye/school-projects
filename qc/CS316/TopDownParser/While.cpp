
//
//  While.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "While.hpp"
void While::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <while>\n", level);
    expr.PrintParseTree(indent + SPACING, level + 1);
    statement.PrintParseTree(indent + SPACING, level + 1);
}
void While::Parse(BufferReader& br)
{
    if (br.equal("while"))
    {
        br.skip("while \t\n\r");
        if (br.equal("("))
        {
            br.skip("( \t\n\r");
            expr.Parse(br);
            if (!br.equal(")"))
            {
                throw "[error] : <while> ) expected";
            }
            br.skip(") \t\n\r");
            statement.Parse(br);
        }
        else
        {
            throw "[error] : <while> ( expected";
        }
    }
}

