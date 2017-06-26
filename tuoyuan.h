#ifndef TUOYUAN_H
#define TUOYUAN_H
#include "curve.h"
#include "point.h"
#include "line.h"
#include "math.h"
class tuoyuan :public curve
{
public:
    tuoyuan();
    void readtuocan(string strfun);
    void analysistuo(float &m, float &a, string strfun);
    float getcoefficient(point &p);
    point calintersection(line &l, point &p, tuoyuan &tuo);
    line gettangent(point &qiepoint);
    point pointoncurve(point &p);
    float caltheta(point &p);
    float calx(float du);
    float caly(float du);
    float a() const;
    void setA(float a);

    float b() const;
    void setB(float b);

    float m() const;
    void setM(float m);

    float n() const;
    void setN(float n);

    float theta() const;
    void setTheta(float theta);

    float a2() const;
    void setA2(float a2);

    float b2() const;
    void setB2(float b2);

private:
    float m_a;
    float m_b;
    float m_a2;
    float m_b2;
    float m_m;
    float m_n;
    float m_theta;

};

#endif // TUOYUAN_H
