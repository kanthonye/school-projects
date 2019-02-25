//======================================================================
//  Author      : Kenneth A Esdaile
//  Date        : Created on 11/09/18.
//  Institution : CUNY Queens College
//  Course      : CSCI368 - Computer Graphics
//  Title       : CSCI368-CG-Proj3 (Interactivity)
//======================================================================
//  Copyright © 2018 Kenneth A Esdaile. All rights reserved.
//======================================================================

/**
 * updates:
 *
 * points can be moved individually, this includes point that
 * make up a polygon and points that are not part of the polygon.
 *
 * moving points inside or outside the polygon will update its color accordingly.
 *
 * points can be removed or added individually. this includes points that
 * are part of the polygon and points that are not part of the polygon
 *
 * polygons can be update with newly added point connect
 */

#define GL_SILENCE_DEPRECATION

#include <math.h>
#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__
#   include <OpenGL/gl.h>
#   include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
#   include <GL\glut.h>
#endif

#define WINDOW_HEIGHT 512.0
#define WINDOW_WIDTH 1024.0

struct vec2
{
    float x,y;
    
    vec2() : x(0.0), y(0.0) {}
    vec2(float x, float y) : x(x), y(y) {}
    
    inline float* operator*()
    {
        return (float*)this;
    }
    void normalize()
    {
        float m = sqrt(x*x + y*y);
        m = (m == 0)? 1.0f : 1.0f / m;
        x = x * m;
        y = y * m;
    }
    inline float dot(const vec2& a) const
    {
        return (x*a.x + y*a.y);
    }
    friend inline vec2 operator-(const vec2& a, const vec2& b);
};

inline vec2 operator-(const vec2& a, const vec2& b)
{
    return vec2(a.x-b.x, a.y-b.y);
}

#define RUBBERBAND_NONE  0
#define RUBBERBAND_POINT 1
#define RUBBERBAND_POLY  2

int curr_index = 0;
int type = GL_LINE_STRIP;
bool antialias = false;
vec2 a,b;

int  total_vertives = 0;
vec2 vert[100];

int  total_points = 0;
vec2 points[100];

int rubberbanding = RUBBERBAND_NONE;
bool outside[100];
float radian = 0.0;



void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (total_vertives==1 && (type == GL_LINE_STRIP || type == GL_LINE_LOOP))
    {
        glBegin(GL_POINTS);
        glVertex2fv(*vert[0]);
        glEnd();
    }
    
    //  DRAW POLYGON : every vertex from 0 to polygon are vertices that make up the polygon
    glBegin(type);
    for (int i=0; i<total_vertives; i++)
    {
        glColor3f(1, 1, 0);
        glVertex2fv(*vert[i]);
    }
    glEnd();
    
    // DRAW POINTS : every vertex from polygon to total_vertives are points
    glBegin(GL_POINTS);
    for (int i=0; i<total_points; i++)
    {
        if (outside[i] == true)
            glColor3f(1.0, 0.0, 0.0);
        else
            glColor3f(1.0, 1.0, 0.0);
        glVertex2fv(*points[i]);
    }
    glEnd();
    
    glutSwapBuffers();
}

int FindVertex(const vec2& v)
{
    vec2 p;
    for (int i=0; i<total_vertives; i++)
    {
        p = vert[i] - v;
        if (p.dot(p) < 16)
        {
            return i;
        }
    }
    return -1;
}

int FindPoint(const vec2& v)
{
    vec2 p;
    for (int i=0; i<total_points; i++)
    {
        p = points[i] - v;
        if (p.dot(p) < 16)
        {
            return i;
        }
    }
    return -1;
}


float NormalZComp(const vec2& a, const vec2& b)
{
    return (a.x * b.y) - (a.y * b.x);
}

bool IsPointInsidePolygon(const vec2& p)
{
    if ( type != GL_LINE_LOOP)
    {
        return false;
    }
    
    // Figure 1
    // 0-----1  suppose this was the drawn polygon
    // | \e/ |  made up of vertices [0,1,2,3]
    // |h a f|  and there is a point a in its center
    // | /g\ |  the angles e,f,g,h must adds up to 360.0
    // 3-----2
    int i;
    radian = 0.0;
    // get the angle e,f,g
    for (i=1; i < total_vertives; i++)
    {
        a = vert[i-1] - p;
        b = vert[ i ] - p;
        a.normalize();
        b.normalize();
        if (NormalZComp(a, b) < 0) // if negetive z normal, subtract ange
        {
            radian -= acos(a.dot(b));
        }
        else // else positive z normal, add ange
        {
            radian += acos(a.dot(b));
        }
    }
    
    // get the angle h
    a = vert[i-1] - p;
    b = vert[ 0 ] - p;
    a.normalize();
    b.normalize();
    if (NormalZComp(a, b) < 0) // if negetive winding, subtract ange
    {
        radian -= acos(a.dot(b));
    }
    else // else positive winding, add ange
    {
        radian += acos(a.dot(b));
    }
    
    radian = abs(radian);
    
    if (radian >= 6.28)
    {
        return true;
    }
    
    return false;
}


void ReTestAllPoints()
{
    for (int i=0; i<total_points; i++)
    {
        outside[i] = false;
        if(!IsPointInsidePolygon(points[i]))
        {
            outside[i] = true;
        }
    }
}


void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
            antialias = !antialias;
            if (antialias) {
                glEnable(GL_BLEND);
                glEnable(GL_LINE_SMOOTH);
            } else {
                glDisable(GL_BLEND);
                glDisable(GL_LINE_SMOOTH);
            }
            break;
            
        case 'c':
            total_vertives = 0;
            break;
            
        case 'l':
            type = GL_LINE_STRIP;
            break;
            
        case 'p':
            type = GL_LINE_LOOP;
            // just incase the polygon was altered in anyway, retest all points,
            // if there exist any, to see if they are inside or outside the polygon
            ReTestAllPoints();
            break;
            
        case 'v':
            type = GL_POINTS;
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}

void Mouse(int key,int state, int x, int y)
{
    vec2 p(x, WINDOW_HEIGHT - 1 - y);
    switch (key)
    {
        case GLUT_LEFT_BUTTON:
            antialias = !antialias;
            if (state == GLUT_DOWN)
            {
                // if type is not line_loop then continue adding new point as part of polygon
                if (type != GL_LINE_LOOP)
                {
                    printf("total_vertives %i\n",total_vertives);
                    rubberbanding = RUBBERBAND_POLY;
                    curr_index = total_vertives++;
                    vert[curr_index] = p;
                }
                // if type is line_loop then there is a polgon. if there is a polygon
                // then every new point is to be tested agains that polygon
                else
                {
                    printf("total_points %i\n",total_points);
                    rubberbanding = RUBBERBAND_POINT;
                    curr_index = total_points++;
                    points[curr_index] = p;
                }
                
                glutPostRedisplay();
            }
            else
            {
                rubberbanding = RUBBERBAND_NONE;
                // retest all points on button release
                ReTestAllPoints();
            }
            break;
            
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                // check if the point to remove is from the polygon
                if ((curr_index = FindVertex(p)) >= 0)
                {
                    if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
                    {
                        // remove vertex v
                        for (int i=curr_index; i<total_vertives; i++)
                        {
                            vert[i] = vert[i+1];
                        }
                        // reduce total vertex ccount
                        total_vertives--;
                    }
                    else
                    {
                        vert[curr_index] = p;
                        rubberbanding = RUBBERBAND_POLY;
                    }
                }
                // check if the point to remove is an individual point, not part of the polygon
                else if ((curr_index = FindPoint(p)) >= 0)
                {
                    if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
                    {
                        // remove point
                        for (int i=curr_index; i<total_points; i++)
                        {
                            points[i]  = points[i+1];
                            outside[i] = outside[i+1];
                        }
                        // reduce total point ccount
                        total_points--;
                    }
                    else
                    {
                        points[curr_index] = p;
                        rubberbanding = RUBBERBAND_POINT;
                    }
                }
            }
            else if (state == GLUT_UP)
            {
                // just incase the polygon or a point position was altered in anyway
                // retest all point to see if they are inside or outside the polygon
                ReTestAllPoints();
            }
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}

void Motion(int x, int y)
{
    if (rubberbanding == RUBBERBAND_POLY && curr_index >= 0)
    {
        vert[curr_index].x = x;
        vert[curr_index].y = WINDOW_HEIGHT - 1 - y;
        glutPostRedisplay();
    }
    else if (rubberbanding == RUBBERBAND_POINT && curr_index >= 0)
    {
        points[curr_index].x = x;
        points[curr_index].y = WINDOW_HEIGHT - 1 - y;
        glutPostRedisplay();
    }
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Project 3 : Interactivity");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
    glutMotionFunc(Motion);
    glutMainLoop();
    
    std::cout << "Hello, World!\n";
    return 0;
}
