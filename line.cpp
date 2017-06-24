#include "line.h"

line::line(float a,float b,float c,float d)
{
    m_startpoint.setpoint(a,b);
    m_endpoint.setpoint(c,d);
    m_k=calk();
    m_b=calb();
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
