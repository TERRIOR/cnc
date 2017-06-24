#include "point.h"

point::point()
{

}

point::point(float a,float b)
{
    setpoint(a,b);
}

void point::setpoint(float a, float b)
{
    m_x=a;
    m_y=b;
}

point::~point()
{

}
void point::showpoint(){
    cout<<"("<<m_x<<","<<m_y<<")"<<endl;
}

float point::x() const
{
    return m_x;
}

float point::y() const
{
    return m_y;
}
