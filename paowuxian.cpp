#include "paowuxian.h"

paowuxian::paowuxian()
{

}

void paowuxian::setpaocan(float a, float b, float c, bool dir)
{
    m_a=a;
    m_b=b;
    m_c=c;
    m_dir=dir;
}

void paowuxian::readpaocan(string str)
{
    if(str[0]=='y'){
        m_dir=true;
        analysisstr(str,"x^2","x");
    }else{
        m_dir=false;
        analysisstr(str,"y^2","y");
    }
}

paowuxian::paowuxian(float a, float b, float c,bool dir)
{
    setpaocan(a,b,c,dir);
}

paowuxian::paowuxian(string str)
{
    readpaocan(str);
}

point paowuxian::pointoncurve(point &p)
{
    float x=p.x();
    float y=getresult(x);
    return point(x,y);
}

paowuxian::~paowuxian()
{

}

bool paowuxian::getDir() const
{
    return m_dir;
}

void paowuxian::setDir(bool value)
{
    m_dir = value;
}

float paowuxian::getresult(float in)
{
    return m_a*in*in+m_b*in+m_c;
}
//计算相交点
point paowuxian::calintersection(line &l, point &p, paowuxian pao)
{
    point IntersectionPoint;
    float x=(l.k()-m_b)/m_a-p.x();//韦达定理 x1+x2=-b/a 此处b=m_b-k
    float y=pao.getresult(x);//根据横坐标，计算在该抛物线的y坐标
    IntersectionPoint.setpoint(x,y);//设置XY
    return IntersectionPoint;
}

float paowuxian::getA() const
{
    return m_a;
}

float paowuxian::getB() const
{
    return m_b;
}

float paowuxian::getC() const
{
    return m_c;
}

line paowuxian::gettangent(point &qiepoint)
{
    float k=getcoefficient(qiepoint);
    float b=qiepoint.y()-k*qiepoint.x();
    line tangent(k,b);
    return tangent;
}

float paowuxian::getcoefficient(point &p)
{
    return 2*m_a*p.x()+m_b;
}

void paowuxian::analysisstr(string str,string square,string one)
{

    int indexping=str.find(square);
    int indexdeng=str.find("=");
    string s_a=str.substr(indexdeng+1,indexping-indexdeng-1);
    if(s_a.empty()){
        m_a=1;
    }else{
        m_a=atof(s_a.c_str());
    }
    str=str.substr(indexping+3);//rest
    if(!str.empty()){
        int indexyi=str.find(one);
        if(indexyi==string::npos){
            m_c=atof(str.substr(1).c_str());
        }else{
            if(indexyi==1) {
               m_b=1;
            }
            else{
               m_b=atof(str.substr(1,indexyi-1).c_str());
            }
            str=str.substr(indexyi+1);
            if(!str.empty()){
                 m_c=atof(str.substr(1).c_str());
            }
        }
    }
}
