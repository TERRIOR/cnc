#include "tuoyuan.h"

tuoyuan::tuoyuan()
{

}

void tuoyuan::readtuocan(string strfun)
{
    //first step find "+"
    int indexplus;//取出y后找出‘+’位置 有m_n存在的情况
    int indexdeng=strfun.find('=');
    if(strfun[strfun.find('y')-2]=='+'){
        indexplus=strfun.find('y')-2;//取出y后找出‘+’位置 有m_n存在的情
    }else if(strfun[strfun.find('y')-1]=='+'){
        indexplus=strfun.find('y')-1;//取出y后找出‘+’位置 有m_n不存在的情
    }
    string strx,stry;
    strx=strfun.substr(0,indexplus);//取出+号前面关于x的方程
    stry=strfun.substr(indexplus+1,indexdeng-indexplus-1);//取出+号后的
    analysistuo(m_m,m_a2,strx);//分析前半段
    analysistuo(m_n,m_b2,stry);//分析后半段
    m_a=sqrt(m_a2);
    m_b=sqrt(m_b2);
}

void tuoyuan::analysistuo(float &m,float &a,string strfun)
{
    int indexchu=strfun.find('/');
    int indexzuo=strfun.find('(');
    int indexyou=strfun.find('(');
    a=atof(strfun.substr(indexchu+1).c_str());//取出÷号后面的数字 并开方得到该方程的a/b
    if(indexzuo==string::npos&&indexyou==string::npos){//没有括号说明没有m/n
        m=0;
    }else{
        m=atof(strfun.substr(3,indexyou-3).c_str());
        if(strfun.find('-')==string::npos)
            m=-m;
    }
}

float tuoyuan::getcoefficient(point &p)
{
    return -m_b2/m_a2*(p.x()-m_m)/(p.y()-m_n);
}

point tuoyuan::calintersection(line &l, point &p, tuoyuan &tuo)
{
    float x1=p.x();
    float y1=p.y();
    float x12=(tuo.a2()*l.k()*(2*tuo.n()-2*l.b())+2*tuo.b2()*tuo.m())
            /(tuo.b2()+tuo.a2()*l.k()*l.k());
    float x2=x12-x1;
    float y12=l.k()*x12+2*l.b();
    float y2=y12-y1;
    point rep=tuo.pointoncurve(point(x2,y2));
    return rep;
}

line tuoyuan::gettangent(point &qiepoint)
{
    line l;
    float k=getcoefficient(qiepoint);
    l.setK(k);
    float b=m_n+m_b*m_b/(qiepoint.y()-m_n)+k*m_n;
    l.setB(b);
    return l;
}

point tuoyuan::pointoncurve(point &p)
{
    float x=p.x();
    float y=sqrt(1-(p.x()-m_m)*(p.x()-m_m)/m_a2)*m_b;
    point rep(x,y);
    if(p.y()-m_n<0){
        rep.setY(-y+m_n);
    }else{
        rep.setY(y+m_n);
    }
    return rep;
}

float tuoyuan::caltheta(point &p)
{
    float theta=acos((p.x()-m_m)/m_a);
    //小于0时，theta的范围在pi到2pi之间
    if(p.y()-m_n<0){
        theta=3.14*2-theta;
    }
    return theta;
}

float tuoyuan::calx(float du)
{
    return m_a*cos(du)+m_m;
}

float tuoyuan::caly(float du)
{
    return m_b*sin(du)+m_n;
}

float tuoyuan::a() const
{
    return m_a;
}

void tuoyuan::setA(float a)
{
    m_a = a;
}

float tuoyuan::b() const
{
    return m_b;
}

void tuoyuan::setB(float b)
{
    m_b = b;
}

float tuoyuan::m() const
{
    return m_m;
}

void tuoyuan::setM(float m)
{
    m_m = m;
}

float tuoyuan::n() const
{
    return m_n;
}

void tuoyuan::setN(float n)
{
    m_n = n;
}

float tuoyuan::theta() const
{
    return m_theta;
}

void tuoyuan::setTheta(float theta)
{
    m_theta = theta;
}

float tuoyuan::a2() const
{
    return m_a2;
}

void tuoyuan::setA2(float a2)
{
    m_a2 = a2;
}

float tuoyuan::b2() const
{
    return m_b2;
}

void tuoyuan::setB2(float b2)
{
    m_b2 = b2;
}

