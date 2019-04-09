//
//  Statement.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "Cond.hpp"
#include "Print.hpp"
#include "While.hpp"
#include "Block.hpp"
#include "Statement.hpp"
#include "Assignment.hpp"
#include "FunCallStatement.hpp"
void Statement::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    printf("%i <statement>\n", level);
    statement->PrintParseTree(indent + SPACING, level + 1);
}
void Statement::Parse(BufferReader& br)
{
    if (br == "{")
    {
        statement = new Block;
        statement->Parse(br);
        return;
    }
    else if (br == "if")
    {
        BufferReader b = br;
        b.skip("if \n\t\r");
        if (b.cequal("("))
        {
            statement = new Cond;
            statement->Parse(br);
            return;
        }
    }
    else if (br == "print")
    {
        BufferReader b = br;
        b.skip("print \n\t\r");
        if (b.cequal("="))
        {
            statement = new Print;
            statement->Parse(br);
            return;
        }
    }
    
    if (br == "while")
    {
        BufferReader b = br;
        b.skip("while \n\t\r");
        if (b.cequal("("))
        {
            statement = new While;
            statement->Parse(br);
            return;
        }
    }
    
    if (br.char_letter() || br.cequal("_"))
    {
        if (br.find("(", "-+*,/=&|;%{}[]&^%$#@!~.?"))
        {
            statement = new FunCallStatement;
            statement->Parse(br);
        }
        else
        {
            statement = new Assignment;
            statement->Parse(br);
        }
    }
    else
    {
        throw "[error] : <statement>";
    }
}
Statement::~ Statement()
{
    if (statement != nullptr)
    {
        delete statement;
        statement = nullptr;
    }
}
Statement::Statement()
:   statement(nullptr)
{}
