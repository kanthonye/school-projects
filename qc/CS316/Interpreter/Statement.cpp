//
//  Statement.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/Cond.hpp"
#include "../CS316/Print.hpp"
#include "../CS316/While.hpp"
#include "../CS316/Block.hpp"
#include "../CS316/Statement.hpp"
#include "../CS316/Assignment.hpp"
#include "../CS316/FunCallStatement.hpp"
void Statement::PrintParseTree(int indent, int level)
{
    PrintSpace(indent);
    IO::Write("%i <statement>\n", level);
    elem->PrintParseTree(indent + SPACING, level + 1);
}
void Statement::M(HashMap<Val>& state)
{
    elem->M(state);
}

Statement::~ Statement()
{
    if (elem != nullptr)
    {
        delete elem;
        elem = nullptr;
    }
}

Statement::Statement(StatementElem* s)
:   elem(s)
{}
