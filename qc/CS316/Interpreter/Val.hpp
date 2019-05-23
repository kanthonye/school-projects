//
//  Val.hpp
//  PROJ3_ InterpreterPart1
//
//  Created by Kenneth A Esdaile on 4/22/19.
//  Copyright © 2019 Kenneth A Esdaile. All rights reserved.
//

#ifndef Val_hpp
#define Val_hpp
#include "../CS316/BaseVal.hpp"
class Val
{
private:
    
    void DeRef()
    {
        if (val != nullptr)
        {
            val->count--;
            if (val->count <= 0)
            {
                delete val;
                val = nullptr;
            }
        }
    }
    void SetRef(BaseVal* v)
    {
        val = v;
        if (val != nullptr)
        {
            val->count++;
        }
    }
    
public:
    
    inline BaseVal* operator ->()
    {
        return val;
    }
    
    inline bool HasVal()
    {
        return val != nullptr;
    }
    void operator=(const Val& v)
    {
        DeRef();
        SetRef(v.val);
    }
    virtual ~Val()
    {
        DeRef();
    }
    Val(const Val& v)
    :   val(nullptr)
    {
        SetRef(v.val);
    }
    Val(BaseVal* v)
    :   val(nullptr)
    {
        SetRef(v);
    }
    
    Val()
    :   val(nullptr)
    {}
    
protected:
    
    BaseVal* val;
};
#endif /* Val_hpp */
