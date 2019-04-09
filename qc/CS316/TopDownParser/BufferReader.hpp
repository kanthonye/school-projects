//
//  BufferReader.hpp
//  PROJ2_TopDownParser
//
//  Created by Kenneth A Esdaile on 4/5/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef BufferReader_hpp
#define BufferReader_hpp
#include <string>
#include <stdio.h>
class BufferReader
{
public:
    
    //long read_chars(char* target, const long size, const char * flags);
    
    long read(char* target, const long size, const char * flags);
    
    long read_letters(char* target, const long size);
    
    long read_digits(char* target, const long size);
    
    long read(char* target, const long size);
    
    long find(const char* str,  const char * flags);
    
    long count(const char * flags);
    
    long seek(const char * flags);
    
    long skip(const char * flags);
    
    bool cequal(const char * t) const;
    
    bool equal(const char * t) const;
    
    long skip_letters();
    
    long skip_digits();
    
    const char* getln();
    
    bool empty();
    
    void operator +=(int n);
    
    void operator ++(int);
    
    inline long char_letter() const
    {
        return (*_chrptr >= 'a' && *_chrptr <= 'z') || (*_chrptr >= 'A' && *_chrptr <= 'Z');
    }
    
    inline long char_digit() const
    {
        return *_chrptr >= '0' && *_chrptr <= '9';
    }
    
    inline void operator =(const BufferReader& br)
    {
        _chrptr = br._chrptr;
    }
    
    inline void operator =(const char* cstr)
    {
        _chrptr = cstr;
    }
    
    inline bool operator ==(const char* cstr) const
    {
        if (_chrptr == nullptr) return false;
        return equal(cstr);
    }
    
    inline bool operator !=(const char* cstr) const
    {
        if (_chrptr == nullptr) return false;
        return !equal(cstr);
    }
    
    inline bool operator ==(int c) const
    {
        return *_chrptr == c;
    }
    
    inline bool operator !=(int c) const
    {
        return *_chrptr != c;
    }
    
    inline bool operator <=(int c) const
    {
        return *_chrptr <= c;
    }
    
    inline bool operator >=(int c) const
    {
        return *_chrptr >= c;
    }
    
    inline bool operator <(int c) const
    {
        return *_chrptr < c;
    }

    inline bool operator >(int c){return *_chrptr > c;}
    inline int ascii(){return *_chrptr;}
    
    bool LoadText(const std::string& filename);
    
    inline void SetBufferReader(const char* bufr){_chrptr = bufr;}
    
    ~ BufferReader();
    BufferReader(const BufferReader& br);
    BufferReader();
    
    
private:
    
    const char* _chrptr;
    char* _buffer;
    int _refcnt;
};
#endif /* BufferReader_hpp */
