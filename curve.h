#ifndef CURVE_H
#define CURVE_H
#include "point.h"

class curve
{
public:
    curve();
    curve(float max,float min);
    ~curve();
    virtual point pointoncurve(point &p);
    float MinValue() const;
    void setMinValue(float MinValue);

    float MaxValue() const;
    void setMaxValue(float MaxValue);

    point startpoint() const;
    void setStartpoint(const point &startpoint);

    point endpoint() const;
    void setEndpoint(const point &endpoint);

private:
    float m_MinValue;
    float m_MaxValue;
    point m_startpoint;
    point m_endpoint;
};

#endif // CURVE_H
