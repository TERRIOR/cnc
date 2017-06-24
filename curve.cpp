#include "curve.h"

curve::curve()
{

}

curve::curve(float max, float min):m_MaxValue(max),m_MinValue(min)
{

}

curve::~curve()
{

}

float curve::MinValue() const
{
    return m_MinValue;
}

void curve::setMinValue(float MinValue)
{
    m_MinValue = MinValue;
}

float curve::MaxValue() const
{
    return m_MaxValue;
}

void curve::setMaxValue(float MaxValue)
{
    m_MaxValue = MaxValue;
}

point curve::startpoint() const
{
    return m_startpoint;
}

void curve::setStartpoint(const point &startpoint)
{
    m_startpoint = startpoint;
}

point curve::endpoint() const
{
    return m_endpoint;
}

void curve::setEndpoint(const point &endpoint)
{
    m_endpoint = endpoint;
}
