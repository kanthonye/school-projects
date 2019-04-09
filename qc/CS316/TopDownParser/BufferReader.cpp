//
//  BufferReader.cpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#include "BufferReader.hpp"

//
//long BufferReader::read_chars(char* target, const long size, const char * flags)
//{
//    while (*flags != 0 && *target != 0 && *flags == *target)
//    {
//        target
//        flags++;
//    }
//    
//    for (s=_chrptr; *s!=0 && cnt<size; s++)
//    {
//        f = flags;
//        while (*f != 0 && *f != *s) f++;
//        if (*f != 0) break;
//        target[cnt++] = *s;
//    }
//    target[cnt] = 0;
//    long written = s - _chrptr;
//    _chrptr += written;
//    return written;
//}

long BufferReader::read(char* target, const long size, const char * flags)
{
    long cnt = 0;
    const char* s, *f;
    for (s=_chrptr; *s!=0 && cnt<size; s++)
    {
        f = flags;
        while (*f != 0 && *f != *s) f++;
        if (*f != 0) break;
        target[cnt++] = *s;
    }
    target[cnt] = 0;
    long written = s - _chrptr;
    _chrptr += written;
    return written;
}

long BufferReader::read_letters(char* target, const long size)
{
    long cnt = 0;
    const char* s;
    for (s=_chrptr; *s!=0 && cnt<size; s++)
    {
        if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
        {
            target[cnt++] = *s;
        }
        else break;
    }
    target[cnt] = 0;
    long written = s - _chrptr;
    _chrptr += written;
    return written;
}

long BufferReader::read_digits(char* target, const long size)
{
    long cnt = 0;
    const char* s;
    for (s=_chrptr; *s!=0 && cnt<size; s++)
    {
        if (*s >= '0' && *s <= '9')
        {
            target[cnt++] = *s;
        }
        else break;
    }
    target[cnt] = 0;
    long written = s - _chrptr;
    _chrptr += written;
    return written;
}

long BufferReader::read(char* target, const long size)
{
    long cnt = 0;
    const char* s;
    for (s=_chrptr; *s!=0 && cnt<size; s++)
    {
        target[cnt++] = *s;
    }
    return s - _chrptr;
}

long BufferReader::find(const char* str,  const char * flags)
{
    const char* s, *f;
    const char* a = _chrptr;
    while (*a != 0)
    {
        s = str;
        while ((*s == *a) && (a!=0 && s!=0))
        {
            s++;
            a++;
        }
        if (*s == 0)  return a - _chrptr;
        
        f = flags;
        while (*a!=*f && *f!=0) f++;
        if (*f!=0) return 0;
        
        a++;
    }
    return 0;
}

long BufferReader::count(const char * flags)
{
    const char* f;
    const char* s = _chrptr;
    while (*s != 0)
    {
        f = flags;
        while (*s != *f && *s != 0 && *f != 0) f++;
        if (*f != 0) break;
        s++;
    }
    return s - _chrptr;
}

long BufferReader::seek(const char * flags)
{
    const char* f;
    const char* s = _chrptr;
    while (*s != 0)
    {
        f = flags;
        while (*f != 0)
        {
            if (*s == *f )
            {
                long n = s - _chrptr;
                _chrptr += n;
                return n;
            }
            f++;
        }
        s++;
    }
    return 0;
}

long BufferReader::skip_letters()
{
    const char* s = _chrptr;
    while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) s++;
    long n = s - _chrptr;
    _chrptr = s;
    return n;
}

long BufferReader::skip_digits()
{
    const char* s = _chrptr;
    while (*s >= '0' && *s <= '9') s++;
    long n = s - _chrptr;
    _chrptr = s;
    return n;
}

long BufferReader::skip(const char * flags)
{
    const char* f = flags;
    const char* s = _chrptr;
    
    f = flags;
    while (*f != 0 && *s == *f)
    {
        f++;
        s++;
    }
    if (*f == 0)
    {
        long n = s - _chrptr;
        _chrptr = s;
        return n;
    }
    const char * rest = f;
    while (*s != 0)
    {
        f = rest;
        while (*f != 0 && *s != *f) f++;
        if (*f == 0) break;
        s++;
    }
    
    long n = s - _chrptr;
    _chrptr = s;
    return n;
}

bool BufferReader::equal(const char * t) const
{
    const char* s = _chrptr;
    while (*s != 0 && *t != 0) if (*s++ != *t++) return false;
    return true;
}

bool BufferReader::cequal(const char * t) const
{
    while (*t != 0)
    {
        if (*_chrptr == *t++) return true;
    }
    return false;
}

const char* BufferReader::getln()
{
    const char* ln = _chrptr;
    seek("\n");
    if (*_chrptr == '\n') _chrptr++;
    return ln;
}

void BufferReader::operator ++(int)
{
    if (_chrptr == nullptr) return;
    if (*_chrptr == 0) return;
    _chrptr++;
}

void BufferReader::operator +=(int n)
{
    if (_chrptr == nullptr) return;
    if (*_chrptr == 0) return;
    _chrptr += n;
}

bool BufferReader::empty()
{
    if (_chrptr == nullptr) return true;
    if (*_chrptr == 0) return true;
    return false;
}

bool BufferReader::LoadText(const std::string& filename)
{
    FILE * file = fopen(filename.c_str(), "r");
    if (!file)
    {
        fprintf(stderr,"error: LoadXML(%s) file not found.\n",filename.c_str());
        return false;
    }
    
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    rewind(file);
    
    if (filesize == 0) return false;
    _buffer = new char[filesize];
    fread(_buffer, filesize, sizeof(char), file);
    _buffer[filesize] = '\0';
    SetBufferReader(_buffer);
    return true;
}

BufferReader::~ BufferReader()
{
    if (_buffer != nullptr)
    {
        delete [] _buffer;
        _buffer = nullptr;
    }
    _chrptr = nullptr;
}

BufferReader::BufferReader(const BufferReader& br)
:   _chrptr(br._chrptr)
,   _buffer(nullptr)
,   _refcnt(0)
{}

BufferReader::BufferReader()
:   _chrptr(nullptr)
,   _buffer(nullptr)
,   _refcnt(0)
{}
