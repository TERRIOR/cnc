#ifndef LINE_H
#define LINE_H
#include "point.h"
#include <cmath>
class line
{
public:
    line();
    line(float a,float b,float c,float d);
    line(float k,float b);
    line(point p,float k);
    float getresult(float x);
    float calculatedis(point yuanxin);

    float b() const;
    void setB(float b);

    float k() const;
    void setK(float k);

    double distance() const;
    void setDistance(double distance);

    point endpoint() const;
    void setEndpoint(const point &endpoint);

    point startpoint() const;
    void setStartpoint(const point &startpoint);

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
