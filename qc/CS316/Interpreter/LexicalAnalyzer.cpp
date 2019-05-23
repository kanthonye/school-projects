//
//  LexicalAnalyzer.cpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/22/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "../CS316/LexicalAnalyzer.hpp"
void LexicalAnalyzer::setKeywordMap()
{
    keywordMap.put("if",        State::Keyword_if);
    keywordMap.put("else",      State::Keyword_else);
    keywordMap.put("while",     State::Keyword_while);
    keywordMap.put("returnVal", State::Keyword_returnVal);
    keywordMap.put("new",       State::Keyword_new);
    keywordMap.put("print",     State::Keyword_print);
}

// This is the driver of the DFA.
// If a valid token is found, assigns it to "t" and returns 1.
// If an invalid token is found, assigns it to "t" and returns 0.
// If end-of-stream is reached without finding any non-whitespace character, returns -1.
int LexicalAnalyzer::driver()
{
    State nextSt; // the next state of the DFA
    
    t = "";
    state = State::Start;
    
    reader.skip("\b \t\n\r");
    if ( reader == -1 ) // end-of-stream is reached
        return -1;
    
    c = reader.ascii();
    while ( !reader.empty() ) // do the body if "a" is not end-of-stream
    {
        nextSt = nextState[state.val][reader.ascii()];
        if ( nextSt == State::UNDEF ) // The DFA will halt.
        {
            if ( state.isFinal() )
            {
                keywordCheck();
                return 1; // valid token extracted
            }
            else
            {
                return 0;
            }
        }
        else // The DFA will go on.
        {
            state = nextSt;
            c = reader.chr();
            t = t+c;
            reader++;
        }
    }
    
    // end-of-stream is reached while a token is being extracted
//    if ( state.isFinal() )
        return 1; // valid token extracted
//    else
//        return 0; // invalid token found
}

void LexicalAnalyzer::setNextState()
{
    for (int s = 0; s <= 31; s++ )
        for (int c = 0; c <= 127; c++ )
            nextState[s][c] = State::UNDEF;
    
    for (char c = 'A'; c <= 'Z'; c++)
    {
        nextState[State::Start][c] = State::Id;
        nextState[State::Id   ][c] = State::Id;
    }
    
    for (char c = 'a'; c <= 'z'; c++)
    {
        nextState[State::Start][c] = State::Id;
        nextState[State::Id   ][c] = State::Id;
    }
    
    for (char d = '0'; d <= '9'; d++)
    {
        nextState[State::Start     ][d] = State::Int;
        nextState[State::Int       ][d] = State::Int;
        nextState[State::Id        ][d] = State::Id;
        nextState[State::Period    ][d] = State::Float;
        nextState[State::Float     ][d] = State::Float;
        nextState[State::E         ][d] = State::FloatE;
        nextState[State::EPlusMinus][d] = State::FloatE;
        nextState[State::FloatE    ][d] = State::FloatE;
    }
    
    nextState[State::Int  ]['.'] = State::Period;
    nextState[State::Float]['e'] = State::E;
    nextState[State::Float]['E'] = State::E;
    nextState[State::E    ]['+'] = State::EPlusMinus;
    nextState[State::E    ]['-'] = State::EPlusMinus;
    
    nextState[State::Start]['+'] = State::Add;
    nextState[State::Start]['-'] = State::Sub;
    nextState[State::Start]['*'] = State::Mul;
    nextState[State::Start]['/'] = State::Div;
    nextState[State::Start]['('] = State::LParen;
    nextState[State::Start][')'] = State::RParen;
    nextState[State::Start]['{'] = State::LBrace;
    nextState[State::Start]['}'] = State::RBrace;
    nextState[State::Start]['['] = State::LBracket;
    nextState[State::Start][']'] = State::RBracket;
    nextState[State::Start][';'] = State::Semicolon;
    nextState[State::Start][','] = State::Comma;
    nextState[State::Start]['|'] = State::Bar;
    nextState[State::Start]['&'] = State::Ampersand;
    nextState[State::Bar  ]['|'] = State::Or;
    nextState[State::Ampersand]['&'] = State::And;
    nextState[State::Start]['!'] = State::Inv;
    nextState[State::Start]['='] = State::Assign;
    nextState[State::Start]['<'] = State::Lt;
    nextState[State::Start]['>'] = State::Gt;
    nextState[State::Inv  ]['='] = State::Neq;
    nextState[State::Assign]['='] = State::Eq;
    nextState[State::Lt   ]['='] = State::Le;
    nextState[State::Gt   ]['='] = State::Ge;
} // end setNextState

void LexicalAnalyzer::keywordCheck()
{
    State keywordState = keywordMap.get(t);
    if ( keywordState.isKeyword() ) // "t" has a keyword
        state = keywordState;
}

// Extract the next token using the driver of the DFA.
// If an invalid token is found, issue an error message.
void LexicalAnalyzer::getToken()
{
    int i = driver();
    if ( state == State::Id )
        keywordCheck();
    else if ( i == 0 )
        WriteLn("%s", (t + " : Lexical Error, invalid token").c_str());
}

// Sets the nextState array and keywordMap.
void LexicalAnalyzer::SetLex()
{
    setNextState();
    setKeywordMap();
}

// argv[0]: input file containing source code using tokens defined above
// argv[1]: output file displaying a list of the tokens
void LexicalAnalyzer::main(const std::string& infile, const std::string& outfile)
{
    SetIO(infile, outfile);
    SetLex();
    
    int i;
    while ( !reader.empty() ) // while "a" is not end-of-stream
    {
        i = driver(); // extract the next token
        if ( i == 1 )
        {
            if ( state == State::Id )
                keywordCheck();
            //Write( t+"   : " + state.toString() );
        }
        else if ( i == 0 )
            WriteLn("%s", t.c_str());
//        Write( t+" : Lexical Error, invalid token");
    }
    
    CloseIO();
}
