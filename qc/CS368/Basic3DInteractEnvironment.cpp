//======================================================================
//  Author      : Kenneth A Esdaile
//  Date        : Created on 12/06/18.
//  Institution : CUNY Queens College
//  Course      : CSCI368 - Computer Graphics
//  Title       : CSCI368-CG-Proj3 (Interactivity)
//======================================================================
//  Copyright © 2018 Kenneth A Esdaile. All rights reserved.
//======================================================================

#define GL_SILENCE_DEPRECATION

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <iostream>

#ifdef __APPLE__
#   include <OpenGL/gl.h>
#   include <GLUT/glut.h>
#   include <sys/time.h>
#elif defined _WIN32 || defined _WIN64
#   include <GL\glut.h>
#   include "windows.h"
#endif


/*! @brief Converting Degrees to Radians */
#define DEG2RAD(degree) ( degree * 0.017453292519f )

/*! @brief Converting Radians to Degrees */
#define RAD2DEG(radian) ( radian * 57.295779513082f )

#define WINDOW_HEIGHT 512.0
#define WINDOW_WIDTH 1024.0

struct vec3
{
    float x,y,z;
    
    vec3() : x(0.0), y(0.0), z(0.0) {}
    vec3(float v) : x(v), y(v), z(v) {}
    vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    inline float* operator*()
    {
        return (float*)this;
    }
    vec3 normalize()
    {
        float m = sqrt(x*x + y*y);
        m = (m == 0)? 1.0f : 1.0f / m;
        x = x * m;
        y = y * m;
        return *this;
    }
    inline vec3 cross(const vec3& b) const
    {
        // | ax ay az |
        // | bx by bz |
        return vec3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
    }
    inline float dot(const vec3& a) const
    {
        return (x*a.x + y*a.y + z*a.z);
    }
    inline vec3 operator-()
    {
        return vec3(-x, -y, -z);
    }
    friend inline vec3 operator-(const vec3& a, const vec3& b);
    friend inline vec3 operator+(const vec3& a, const vec3& b);
};

inline vec3 operator+(const vec3& a, const vec3& b)
{
    return vec3(a.x+b.x, a.y+b.y, a.z+b.z);
}
inline vec3 operator-(const vec3& a, const vec3& b)
{
    return vec3(a.x-b.x, a.y-b.y, a.z-b.z);
}

struct vec4
{
    float x,y,z,w;
    
    vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    
};

inline vec4 quat_mult(const vec4 &p,const vec4 &q)
{
    return vec4
    (  p.w*q.w - p.x*q.x - p.y*q.y - p.z*q.z
     , p.w*q.x + p.x*q.w + p.y*q.z - p.z*q.y
     , p.w*q.y - p.x*q.z + p.y*q.w + p.z*q.x
     , p.w*q.z + p.x*q.y - p.y*q.x + p.z*q.w  );
}

void quat2m33
(  float r[3]
 , float u[3]
 , float f[3]
 , const vec4& q)
{
    float xx = 2 * (q.x * q.x);
    float xy = 2 * (q.x * q.y);
    float xz = 2 * (q.x * q.z);
    float xw = 2 * (q.w * q.x);
    
    float yy = 2 * (q.y * q.y);
    float yz = 2 * (q.y * q.z);
    float yw = 2 * (q.w * q.y);
    
    float zz = 2 * (q.z * q.z);
    float zw = 2 * (q.w * q.z);
    
    r[0] = 1 - (yy + zz);
    r[1] =     (xy - zw);
    r[2] =     (xz + yw);
    
    u[0] =     (xy + zw);
    u[1] = 1 - (xx + zz);
    u[2] =     (yz - xw);
    
    f[0] =     (xz - yw);
    f[1] =     (yz + xw);
    f[2] = 1 - (xx + yy);
}



void DrawBox(const vec3& p_min, const vec3& p_max)
{
    // bottom plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(p_min.x, p_min.y, p_min.z);
    glVertex3f(p_max.x, p_min.y, p_min.z);
    glVertex3f(p_min.x, p_min.y, p_max.z);
    glVertex3f(p_max.x, p_min.y, p_max.z);
    glEnd();
    
    // top plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(p_max.x, p_max.y, p_max.z);
    glVertex3f(p_max.x, p_max.y, p_min.z);
    glVertex3f(p_min.x, p_max.y, p_max.z);
    glVertex3f(p_min.x, p_max.y, p_min.z);
    glEnd();
    
    // front plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(p_max.x, p_max.y, p_max.z);
    glVertex3f(p_min.x, p_max.y, p_max.z);
    glVertex3f(p_max.x, p_min.y, p_max.z);
    glVertex3f(p_min.x, p_min.y, p_max.z);
    glEnd();
    
    // back plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(p_min.x, p_min.y, p_min.z);
    glVertex3f(p_min.x, p_max.y, p_min.z);
    glVertex3f(p_max.x, p_min.y, p_min.z);
    glVertex3f(p_max.x, p_max.y, p_min.z);
    glEnd();
    
    // left plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(p_min.x, p_min.y, p_min.z);
    glVertex3f(p_min.x, p_min.y, p_max.z);
    glVertex3f(p_min.x, p_max.y, p_min.z);
    glVertex3f(p_min.x, p_max.y, p_max.z);
    glEnd();
    
    // right plane
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(p_max.x, p_max.y, p_max.z);
    glVertex3f(p_max.x, p_min.y, p_max.z);
    glVertex3f(p_max.x, p_max.y, p_min.z);
    glVertex3f(p_max.x, p_min.y, p_min.z);
    glEnd();
}

struct Mouse
{
    double dx;
    double dy;
    double x;
    double y;
} mouse;

struct Keyboard
{
    static bool special_keys[256];
    static bool keys[256];
    static void KeyDown(unsigned char key, int x, int y)
    {
        keys[key] = true;
    }
    static void KeyUp(unsigned char key, int x, int y)
    {
        keys[key] = false;
    }
    static void KeySpecialDown(int key, int x, int y)
    {
        special_keys[key] = true;
    }
    static void KeySpecialUp(int key, int x, int y)
    {
        special_keys[key] = false;
    }
};

bool Keyboard::special_keys[256];
bool Keyboard::keys[256];



class Object
{
public:

    void SetMaterial()
    {
        glEnable(GL_COLOR_MATERIAL);
        glColor3f(color.x, color.y, color.z);
        glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
        glMaterialfv(GL_FRONT, GL_SPECULAR, *specular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, *ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, *color);
        glMateriali(GL_FRONT,GL_SHININESS,128);
    }
    virtual void DrawChildren()
    {
        for (std::vector<Object*>::iterator i=objects.begin(); i!=objects.end(); i++)
        {
            (*i)->Draw();
        }
    }
    virtual void DrawObject(){}
    
    virtual void Draw()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslated(position.x, position.y, position.z);
        glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
        glScalef(scale.x, scale.y, scale.z);
        
        DrawChildren();
        
        if (lit)
        {
            glEnable(GL_LIGHTING);
        }
        else
        {
            glDisable(GL_LIGHTING);
        }
        
        DrawObject();
        
        glPopMatrix();
    }
    
    virtual void UpdateChildren(double ms)
    {
        for (std::vector<Object*>::iterator i=objects.begin(); i!=objects.end(); i++)
        {
            (*i)->Update(ms);
        }
    }
    
    virtual void UpdateObject(double ms)
    {
    }
    
    virtual void Update(double ms)
    {
        UpdateChildren(ms);
        UpdateObject(ms);
    }
    
    virtual void SetParent(Object* parent)
    {
        this->parent = parent;
    }
    
    Object* Attach(Object* object)
    {
        objects.push_back(object);
        object->SetParent(this);
        return object;
    }
    virtual ~Object()
    {
        for (std::vector<Object*>::iterator i=objects.begin(); i!=objects.end(); i++)
            delete (Object*)(*i);
        objects.clear();
    }
    
    Object(const vec3& c, const vec3& p, const vec3& s, const vec3& r)
    :   color(c)
    ,   rotation(r)
    ,   position(p)
    ,   scale(s)
    ,   lit(true)
    {}
    
    Object(const vec3& c, const vec3& p, const vec3& s)
    :   color(c)
    ,   position(p)
    ,   scale(s)
    ,   lit(true)
    {}
    
    Object(const vec3& c, const vec3& p)
    :   color(c)
    ,   position(p)
    ,   scale(1.0)
    ,   lit(true)
    {}
    
    Object(const vec3& c)
    :   color(c)
    ,   scale(1.0)
    ,   lit(true)
    {}
    
    Object()
    :   color(0.6, 0.6, 0.6)
    ,   scale(1.0)
    ,   lit(true)
    {}
    
    std::vector<Object*> objects;
    Object* parent;
    vec3 position;
    vec3 rotation;
    vec3 scale;

    vec3 specular;
    vec3 ambient;
    vec3 color;
    bool lit;
}scene;

class Camera : public Object
{
public:
    
    void Draw(){};
    
    void Rotate(double x, double y)
    {
        rotation.x -= x;
        rotation.y -= y;
    }
    void UpdateViewMatrix()
    {
        float cosPitch = cos(DEG2RAD(rotation.y));
        float sinPitch = sin(DEG2RAD(rotation.y));
        float cosYaw = cos(DEG2RAD(rotation.x));
        float sinYaw = sin(DEG2RAD(rotation.x));
        
        r = vec3( cosYaw, 0, -sinYaw );
        u = vec3( sinYaw * sinPitch, cosPitch, cosYaw * sinPitch );
        f = vec3( sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw );
        
        view[ 0] =  r.x;
        view[ 4] =  r.y;
        view[ 8] =  r.z;
        view[12] = -position.dot(r);
        
        view[ 1] =  u.x;
        view[ 5] =  u.y;
        view[ 9] =  u.z;
        view[13] = -position.dot(u);
        
        view[ 2] =  f.x;
        view[ 6] =  f.y;
        view[10] =  f.z;
        view[14] = -position.dot(f);
        
        view[ 3] = 0.0f;
        view[ 7] = 0.0;
        view[11] = 0.0;
        view[15] = 1.0f;
    }
    
    void ComputeProjectionMatrix(double p_fov, double p_aspect, double p_near, double p_far)
    {
        proj[14] =  tan(DEG2RAD(p_fov* 0.5)) * p_near; // t : TOP
        proj[13] = -proj[14]; // b : BOTTON
        proj[12] =  proj[14] * p_aspect; // r : RIGHT
        proj[11] = -proj[12];          // l : LEFT
        
        proj[15] =  2.0 * p_near;
        
        proj[ 0] = proj[15] / (proj[12] - proj[11]); //  2n / (r-l)
        proj[ 1] = 0.0;
        proj[ 2] = 0.0;
        proj[ 3] = 0.0;
        
        proj[ 4] = 0.0;
        proj[ 5] = proj[15] / (proj[14] - proj[13]);  //  2n / (t-b)
        proj[ 6] = 0.0;
        proj[ 7] = 0.0;
        
        proj[15] = (p_far - p_near);
        
        proj[ 8] =  (proj[12] + proj[11]) / (proj[12] - proj[11]);
        proj[ 9] =  (proj[14] + proj[13]) / (proj[14] - proj[13]);
        proj[10] = -(p_far + p_near) / proj[15];
        proj[11] = -1.0;
        
        proj[12] = 0.0;
        proj[13] = 0.0;
        proj[14] = -(2.0 * p_far * p_near) / proj[15];
        proj[15] = 0.0;
    }
    
    void PushViewProjectionMatrix()
    {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadMatrixf(proj);
        
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadMatrixf(view);
    }
    
    void PopViewProjectionMatrix()
    {
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }
    
    Camera(float p_fov, float p_aspect, float p_near, float p_far)
    :   position(0.0, 7.5, 17.0)
    ,   rotation(-1.0, -8.0, 0.0)
    ,   f(0.01, 0.13, 0.99)
    ,   r(0.99, 0.0, 0.01)
    ,   u(0.0, 0.99, -0.13)
    ,   speed(0.08)
    {
        view[ 0] = r.x;
        view[ 4] = r.y;
        view[ 8] = r.z;
        
        view[ 1] = u.x;
        view[ 5] = u.y;
        view[ 9] = u.z;
        
        view[ 2] = f.x;
        view[ 6] = f.y;
        view[10] = f.z;
        
        view[12] = -position.dot(r);
        view[13] = -position.dot(u);
        view[14] = -position.dot(f);
        
        view[ 3] = 0.0f;
        view[ 7] = 0.0f;
        view[11] = 0.0f;
        view[15] = 1.0f;
        
        ComputeProjectionMatrix(p_fov, p_aspect, p_near, p_far);
    }
    
    float proj[16];
    float view[16];
    vec3 position;
    vec3 rotation;
    vec3 r,u,f;
    
    float speed;
};
static Camera* camera = nullptr;

class Light : public Object
{
public:
    
    virtual void DrawObject()
    {
        light_nmbr = (light_nmbr < GL_LIGHT0) ? GL_LIGHT0 : (light_nmbr >= GL_LIGHT4)? GL_LIGHT4 : GL_LIGHT0;
        
        glEnable(light_nmbr);
        glLightfv(light_nmbr, GL_POSITION, *position);
        glLightfv(light_nmbr, GL_AMBIENT , *ambient);
        glLightfv(light_nmbr, GL_DIFFUSE , *color);
        glLightfv(light_nmbr, GL_SPECULAR, *specular);
    }
    
    virtual void Draw()
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslated(position.x, position.y, position.z);
        glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
        glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
        glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
        glScalef(scale.x, scale.y, scale.z);
        
        DrawChildren();
        DrawObject();
        
        glPopMatrix();
    }
    
    Light(short nmbr, const vec3& p, const vec3& c)
    :   Object(c,p)
    ,   light_nmbr(nmbr)
    {
        ambient = vec3(0.3);
        specular = vec3(1.0);
    }
    
    Light(short nmbr, const vec3& p)
    :   Object(vec3(1),p)
    ,   light_nmbr(nmbr)
    {
        ambient = vec3(0.3);
        specular = vec3(1.0);
    }
    
    Light(short nmbr)
    :   light_nmbr(nmbr)
    {
        ambient = vec3(0.3);
        specular = vec3(1.0);
    }
    
    vec3  ambient;
    vec3  specular;
    short light_nmbr;
};

class Blinker : public Object
{
public:
    
    void UpdateObject(double ms)
    {
        r = (r >= max_deg)? 0.0 : r+s*ms;
        float m = sin(DEG2RAD(r));
        m = (m <= _min)? _min : m;
        m = (m >= _max)? 1.0 : m;
        parent->color.x = color.x * m;
        parent->color.y = color.y * m;
        parent->color.z = color.z * m;
    }
    void SetParent(Object* parent)
    {
        Object::SetParent(parent);
        parent->lit = false;
    }
    
    float r;
    float s;
    float _min;
    float _max;
    float max_deg;
    Blinker(const vec3& c, float max_deg, float mn, float mx, float s)
    : Object(c), max_deg(max_deg), r(0.0), s(s), _min(mn), _max(mx)
    {}
};

class YRotater : public Object
{
public:
    
    void UpdateObject(double ms)
    {
        r = (r >= mx)? 0.0 : r+s*ms;
        parent->rotation.y = r;
    }
    float r;
    float s;
    float mx;
    YRotater(float s)
    : r(0.0), s(s), mx(360)
    {}
};

class Box : public Object
{
public:
    
    void DrawObject()
    {
        SetMaterial();
        DrawBox(mn, mx);
    }
    
    Box(const vec3 c, const vec3 mn, const vec3 mx, const vec3 p)
    :   Object(c, p)
    ,   mn(mn)
    ,   mx(mx)
    {}
    
    Box(const vec3 c, const vec3 mn, const vec3 mx)
    :   Object(c)
    ,   mn(mn)
    ,   mx(mx)
    {}
    
    vec3 mn; // min point on box
    vec3 mx; // max point on box
};

class Sphere : public Object
{
public:
    
    Sphere(const vec3 colr, const vec3 p, GLdouble radius, GLint slices, GLint stacks)
    :   Object(colr, p)
    ,   radius(radius)
    ,   slices(slices)
    ,   stacks(stacks)
    {}
    void DrawObject()
    {
        glColor3f(color.x, color.y, color.z);
        glutSolidSphere(radius, slices, stacks);
    }
    GLdouble radius;
    GLint slices;
    GLint stacks;
};



class Plane : public Object
{
public:
    
    void DrawObject()
    {
        SetMaterial();
        // bottom plane
        glBegin(GL_TRIANGLE_STRIP);
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(-width, 0.0f, -length);
        glVertex3f(-width, 0.0f,  length);
        glVertex3f( width, 0.0f, -length);
        glVertex3f( width, 0.0f,  length);
        glEnd();
    }
    
    Plane(const float length, const float width, const vec3 p)
    :   Object(p)
    ,   length(length*0.5)
    ,   width(width*0.5)
    {}

    Plane(const float length, const float width)
    :   length(length*0.5)
    ,   width(width*0.5)
    {}
    
    float length;
    float width;
};

Object* MakeChair(const vec3&p, const vec3&r, const vec3&s)
{
    vec3 mn,mx,color;
    
    Object* chair = new Object(vec3(), p, s, r);
    {
        mn = vec3(-0.05,-1.0, -1.0);
        mx = vec3( 0.05, 2.0,  1.0);
        color = vec3(0.4, 0.4, 0.4);
        
        Object* back = chair->Attach(new Box(color, mn,mx, vec3(0,3,0)));
        
        mn = vec3(-1.0, 0.00, -1.0);
        mx = vec3( 1.0, 0.5,  1.0);
        
        Object* seat = back->Attach(new Box(color, mn,mx, vec3(-1,-1,0)));
        
        mn = vec3(-0.05,-2.0, -0.05);
        mx = vec3( 0.05, 0.0,  0.05);
        
        // table feet
        seat->Attach(new Box(color, mn,mx, vec3(-0.85, 0,-0.85)));
        seat->Attach(new Box(color, mn,mx, vec3( 0.95, 0,-0.85)));
        seat->Attach(new Box(color, mn,mx, vec3(-0.85, 0, 0.85)));
        seat->Attach(new Box(color, mn,mx, vec3( 0.95, 0, 0.85)));
    }
    return chair;
}

Object* MakeFan(const vec3&p, const vec3&r, const vec3&s)
{
    vec3 mn,mx,color;
    
    mn = vec3(-0.25,-0.0,-0.25);
    mx = vec3(0.25, 5, 0.25);
    color = vec3(1.0,0.4,0.2);
    
    Object* fan = new Box(color, mn,mx, vec3(0,15,0));
    
    mn = vec3( 0.0,-0.25,-0.25);
    mx = vec3( 4.0, 0.25, 0.25);
    color = vec3(1.0,1.0,1.0);
    
    Object* obj = fan->Attach(new Sphere(color, vec3(0.0, 0, 0.0), 1,8,8));
    obj->Attach(new YRotater(1.5));
    
    mn = vec3(0.0,-0.025,-0.5);
    mx = vec3(7.0, 0.025, 0.5);
    //color = vec3(1.0,0.4,0.2);
    
    obj->Attach(new Box(color, mn,mx, vec3(0, 0 ,0)));
    
    mn = vec3(-7.0,-0.025,-0.5);
    mx = vec3(0.0, 0.025, 0.5);
    
    obj->Attach(new Box(color, mn,mx, vec3(0, 0 ,0)));
    
    mn = vec3(-0.5,-0.025, -7.0);
    mx = vec3(0.5, 0.025, 0.0);
    
    obj->Attach(new Box(color, mn,mx, vec3(0, 0 ,0)));
    
    mn = vec3(-0.5,-0.025, 0.0);
    mx = vec3(0.5, 0.025, 7.0);
    
    obj->Attach(new Box(color, mn,mx, vec3(0, 0 ,0)));
    
    return fan;
}

Object* MakeTable(const vec3&p, const vec3&r, const vec3&s)
{
    vec3 color = vec3(1.0,0,1.0);
    vec3 mn = vec3(-4.0, 0.0, -4.0);
    vec3 mx = vec3( 4.0, 0.125,  4.0);
    Object* table = new Box(color, mn,mx, p);
    {
        mn = vec3(-0.5, -4.0, -0.5);
        mx = vec3( 0.5, 0.0,  0.5);
        color = vec3(0.6,0,0.6);
        // table feet
        table->Attach(new Box(color, mn,mx, vec3(-2, 0,-2)));
        table->Attach(new Box(color, mn,mx, vec3( 2, 0,-2)));
        table->Attach(new Box(color, mn,mx, vec3(-2, 0, 2)));
        table->Attach(new Box(color, mn,mx, vec3( 2, 0, 2)));
    }
    return table;
}

Object* MakeSnowman(const vec3&p, const vec3&r, const vec3&s)
{
    // snowman feet
    Object* snowman = new Sphere(vec3(0.7,0.8,1.0), vec3(), 3, 16, 16);
    snowman->position = p;//vec3(-10,2.1,10);
    snowman->rotation = r;//vec3(-10,2.1,10);
    snowman->scale = s;//vec3(-10,2.1,10);
    // snowman torse
    Object* obj = snowman->Attach(new Sphere(vec3(0.7,0.8,1.0), vec3(), 2, 16, 16));
    obj->position = vec3(0,3.5,0);
    // snowman hands
    obj->Attach(new Box(vec3(0.2), vec3(-0.2,-0.2,-0.2), vec3(2.0,0.2,0.2)))->position = vec3(-3.5,1,0);
    obj->Attach(new Box(vec3(0.2), vec3(-0.2,-0.2,-0.2), vec3(2.0,0.2,0.2)))->position = vec3( 1.5,1,0);
    // snowman head
    obj = obj->Attach(new Sphere(vec3(0.7,0.8,1.0), vec3(), 1, 16, 16));
    obj->position = vec3(0,2.5,0);
    // snowman nose
    Object* nose = obj->Attach(new Box(vec3(0.1,0.5,0.8), vec3(-0.05,-0.05,-0.05), vec3(0.05,0.05,0.5)));
    nose->position = vec3(0,0,1);
    nose->Attach(new Blinker(vec3(1,0,0), 90, 0.1, 0.5, 2));
    // snowman eyes
    obj->Attach(new Box(vec3(0.2), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3(-0.3, 0.2, 0.8);
    obj->Attach(new Box(vec3(0.2), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3( 0.3, 0.2, 0.8);
    // snowman teeth
    obj->Attach(new Box(vec3(0.5), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3(-0.4, -0.20, 0.8);
    obj->Attach(new Box(vec3(0.5), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3(-0.2, -0.28, 0.87);
    obj->Attach(new Box(vec3(0.5), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3( 0.0, -0.30, 0.9);
    obj->Attach(new Box(vec3(0.5), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3( 0.2, -0.28, 0.87);
    obj->Attach(new Box(vec3(0.5), vec3(-0.08,-0.08,-0.05), vec3(0.08,0.08,0.15)))->position = vec3( 0.4, -0.20, 0.8);
    return snowman;
}

Object* MakeTree(const vec3&p, const vec3&r, const vec3&s)
{
    vec3 mn,mx,color;
    mn = vec3(-1.5, 0, -1.5);
    mx = vec3(1.5, 2, 1.5);
    color = vec3(0.2);
    Object* pot = new Box(color, mn,mx, p + vec3(0,1,0));
    pot->rotation = r;
    pot->scale = s;
    mn = vec3(-0.25,0.0,-0.25);
    mx = vec3(0.25, 11.0, 0.25);
    color = vec3(0.3);
    Object* tree = pot->Attach(new Box(color, mn,mx, vec3()));
    
    color = vec3(0.114, 0.588, 0.533);
    tree = tree->Attach(new Sphere(color, vec3(0,9,0), 3, 16, 16));
    tree->Attach(new Sphere(color, vec3( 1.5,-2.1,-1.5), 2, 16, 16));
    tree->Attach(new Sphere(color, vec3(-1.5,-2.1,-1.5), 2, 16, 16));
    tree->Attach(new Sphere(color, vec3(-1.5,-2.1, 1.5), 2, 16, 16));
    tree->Attach(new Sphere(color, vec3( 1.5,-2.1, 1.5), 2, 16, 16));
    return pot;
}

void UpdateInput(double ms)
{
    if (Keyboard::keys['a'] || Keyboard::special_keys[GLUT_KEY_LEFT])
    {
        camera->position.x -= camera->r.x * camera->speed * ms;
        camera->position.y -= camera->r.y * camera->speed * ms;
        camera->position.z -= camera->r.z * camera->speed * ms;
    }
    if (Keyboard::keys['d'] || Keyboard::special_keys[GLUT_KEY_RIGHT])
    {
        camera->position.x += camera->r.x * camera->speed * ms;
        camera->position.y += camera->r.y * camera->speed * ms;
        camera->position.z += camera->r.z * camera->speed * ms;
    }
    if (Keyboard::keys['w'] || Keyboard::special_keys[GLUT_KEY_UP])
    {
        camera->position.x -= camera->f.x * camera->speed * ms;
        camera->position.y -= camera->f.y * camera->speed * ms;
        camera->position.z -= camera->f.z * camera->speed * ms;
    }
    if (Keyboard::keys['s'] || Keyboard::special_keys[GLUT_KEY_DOWN])
    {
        camera->position.x += camera->f.x * camera->speed * ms;
        camera->position.y += camera->f.y * camera->speed * ms;
        camera->position.z += camera->f.z * camera->speed * ms;
    }
    if (Keyboard::keys[' '])
    {
        camera->position.x += camera->u.x * camera->speed * ms;
        camera->position.y += camera->u.y * camera->speed * ms;
        camera->position.z += camera->u.z * camera->speed * ms;
    }
    if (Keyboard::keys['m'])
    {
        camera->position.x -= camera->u.x * camera->speed * ms;
        camera->position.y -= camera->u.y * camera->speed * ms;
        camera->position.z -= camera->u.z * camera->speed * ms;
    }
    
    if (Keyboard::keys['r'])
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if (Keyboard::keys['f'])
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    camera->Rotate(mouse.dx, mouse.dy);
    mouse.dx = 0;
    mouse.dy = 0;
}

void Mouse(int key, int state, int x, int y)
{
    mouse.x = x;
    mouse.y = y;
}

void Motion(int x, int y)
{
    mouse.dx = x - mouse.x;
    mouse.dy = y - mouse.y;
    mouse.x = x;
    mouse.y = y;
}

void UpdateGraphics()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    camera->UpdateViewMatrix();
    camera->PushViewProjectionMatrix();
    {
        scene.Draw();
    }
    camera->PopViewProjectionMatrix();
    
    glutSwapBuffers();
    glutPostRedisplay();
}

double GetTimeTick()
{
    static long prev_tick = 0;
    static long curr_tick = 0;
    std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
    curr_tick = ms.count();
    if (prev_tick == 0) prev_tick = curr_tick;
    double delta = curr_tick - prev_tick;
    prev_tick = curr_tick;
    return delta;
}

void Display()
{
    double msec = 0.1 * GetTimeTick();
    //printf("%f\n", msec);
    UpdateInput(msec);
    scene.Update(msec);
    UpdateGraphics();
}


void InitScene()
{
    float aspect = double(WINDOW_WIDTH)/double(WINDOW_HEIGHT);
    scene.Attach( (camera = new Camera(75.0, aspect, 0.1, 1000)) );
    
    vec3 min   = vec3(-0.25,-11.0,-0.25);
    vec3 max   = vec3(0.25, 0.0, 0.25);
    vec3 color = vec3(1.0,1.0,0.5);
    
    Object* obj = scene.Attach( new Light(1, vec3(8,11,-8), color) );
    obj->Attach( new Box(vec3(0.278,0.490,0.851), min,max, vec3()) );
    obj->Attach( new Sphere(color, vec3(), 1, 16, 16) )->lit = false;
    
    scene.Attach( new Plane(36,36) );
    scene.Attach( MakeTable(vec3(0, 4,0) , vec3(0,  0,0), vec3(1)) );
    scene.Attach( MakeFan(vec3(0,15,0) , vec3(0,  0,0), vec3(1))   );
    scene.Attach( MakeChair(vec3(5,0,0) , vec3(0,  0,0), vec3(1))  );
    scene.Attach( MakeChair(vec3(-5,0,0), vec3(0,180,0), vec3(1))  );
    scene.Attach( MakeChair(vec3(0,0,5) , vec3(0,270,0), vec3(1))  );
    scene.Attach( MakeChair(vec3(0,0,-5), vec3(0, 90,0), vec3(1))  );
    scene.Attach( MakeTree(vec3(-8,0,-8), vec3(), vec3(1)));
    scene.Attach( MakeTree(vec3( 8,0, 8), vec3(), vec3(0.6)));
    scene.Attach( MakeTree(vec3(-8,0, 8), vec3(), vec3(0.8)));
    scene.Attach( MakeSnowman(vec3(8,2,-8), vec3(0,0,0), vec3(1.0)));
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Kenneth A Esdaile Final Project");
    glClearColor(0.7, 0.7, 0.7, 1.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutKeyboardFunc(Keyboard::KeyDown);
    glutKeyboardUpFunc(Keyboard::KeyUp);
    glutSpecialFunc(Keyboard::KeySpecialDown);
    glutSpecialUpFunc(Keyboard::KeySpecialUp);
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_MODE);
    InitScene();
    
    printf("%s\n\n", "Camera Motion Control");
    printf(" - %s\n", " move-forward  : W or UP key");
    printf(" - %s\n", " move-backward : S or DOWN key");
    printf(" - %s\n", "move-rightward : A or RIGHT key");
    printf(" - %s\n", " move-leftward : D or LEFT key");
    printf(" - %s\n", " move-downward : M key");
    printf(" - %s\n", "  move-upward  : SPACE key");
    printf("\n");
    printf("%s\n\n", "Camera Rotation Control");
    printf(" - %s\n", " press and move mouse.");
    glutMainLoop();

    return 0;
}
