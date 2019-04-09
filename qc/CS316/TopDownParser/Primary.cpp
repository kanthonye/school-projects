//
//  Primary.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Primary.hpp"
#include "VarPrimary.hpp"
#include "Expr.hpp"
#include "FunCallPrimary.hpp"

void Primary::PrintParseTree(int indent, int level)
{
    if(!preval.empty())
    {
        PrintSpace(indent);
        printf("%i <primary>\n", level);
        
        PrintSpace(indent + SPACING);
        printf("%i %s\n", level+1, preval.c_str());
        if(primary != nullptr)
        {
            primary->PrintParseTree(indent + SPACING, level + 1);
        }
    }
    else if(primary != nullptr)
    {
        primary->PrintParseTree(indent, level);
    }
}
void Primary::Parse(BufferReader& br)
{
    if (br == '!')
    {
        br++;
        primary = new Primary;
        primary->preval = "!";
        br.skip(" \n\t\r");
        primary->Parse(br);
    }
    else if (br == '-')
    {
        br++;
        primary = new Primary;
        primary->preval = "-";
        br.skip(" \n\t\r");
        primary->Parse(br);
    }
    else if (br.char_digit())
    {
        long i = 0;
        char numeric[64];
        i += br.read_digits(&numeric[i], 64-i);
        if (br == '.')
        {
            numeric[i++] = '.';
            br.skip(".");
            i += br.read_digits(&numeric[i], 64-i);
            if (br.cequal("eE"))
            {
                i += br.read(&numeric[i], 1, "");
                if (br == '+' || br == '-')
                {
                    i += br.read(&numeric[i], 1, "");
                }
                i += br.read_digits(&numeric[i], 64-i);
                primary = new FloatE(numeric);
            }
            else
            {
                primary = new Float(numeric);
            }
        }
        else
        {
            primary = new Int(numeric);
        }
        br.skip(" \n\t\r");
    }
    else if (br.equal("("))
    {
        br.skip("( \t\n\r");
        primary = new Expr;
        primary->Parse(br);
        if (br != ")")
        {
            throw "[error] : <primary> ) expected";
        }
        br.skip(") \t\n\r");
    }
    else
    {
        if (br.find("(", "-+*,/=)&|;%{}[]&^%$#@!~.?"))
        {
            primary = new FunCallPrimary;
            primary->Parse(br);
        }
        else
        {
            primary = new VarPrimary;
            primary->Parse(br);
        }
    }
}
Primary::~ Primary()
{
    if (primary != nullptr)
    {
        delete primary;
        primary = nullptr;
    }
}
