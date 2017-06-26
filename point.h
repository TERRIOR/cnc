#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class point
{
public:
    point();
    point(float a,float b);
    void setpoint(float a,float b);
    ~point();
    void showpoint();
    float x() const;

    float y() const;

    void setX(float x);

    void setY(float y);

private:
    float m_x;
    float m_y;
};

#endif // POINT_H
