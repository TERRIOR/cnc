#ifndef LINE_H
#define LINE_H
#include "point.h"
#include <cmath>
class line
{
public:
    line();
    line(float a,float b,float c,float d);
    float calculatedis(point yuanxin);

private:
    float calk();
    float calb();
    point m_startpoint;
    point m_endpoint;
    double m_distance;
    float m_k;
    float m_b;
};

#endif // LINE_H
