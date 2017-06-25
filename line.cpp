#include "line.h"

line::line(float a,float b,float c,float d)
{
    m_startpoint.setpoint(a,b);
    m_endpoint.setpoint(c,d);
    m_k=calk();
    m_b=calb();
}

line::line(float k, float b):m_k(k),m_b(b)
{

}

line::line(point p, float k):m_k(k)
{
    m_b=p.y()-m_k*p.x();
}

float line::getresult(float x)
{
    return m_k*x+m_b;
}
float line::calculatedis(point yuanxin){

    return abs(yuanxin.y()-m_k*yuanxin.x()-m_b)/sqrt(1+m_k*m_k);
}

float line::calk(){
    return (m_endpoint.y()-m_startpoint.y())/(m_endpoint.x()-m_endpoint.x());
}

float line::calb(){
    return (m_startpoint.y()*m_endpoint.x()-m_startpoint.x()*m_endpoint.y())/(m_endpoint.x()-m_endpoint.x());
}

point line::startpoint() const
{
    return m_startpoint;
}

void line::setStartpoint(const point &startpoint)
{
    m_startpoint = startpoint;
}

point line::endpoint() const
{
    return m_endpoint;
}

void line::setEndpoint(const point &endpoint)
{
    m_endpoint = endpoint;
}

double line::distance() const
{
    return m_distance;
}

void line::setDistance(double distance)
{
    m_distance = distance;
}

float line::k() const
{
    return m_k;
}

void line::setK(float k)
{
    m_k = k;
}

float line::b() const
{
    return m_b;
}

void line::setB(float b)
{
    m_b = b;
}
