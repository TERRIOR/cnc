#ifndef PAOWUXIAN_H
#define PAOWUXIAN_H
#include "point.h"
#include "line.h"
#include "curve.h"
class paowuxian:public curve
{
public:
    paowuxian();
    paowuxian(float a,float b,float c,bool dir);
    paowuxian(string str);
    void setpaocan(float a,float b,float c,bool dir);
    void readpaocan(string str);
    ~paowuxian();
    bool getDir() const;//获取方向
    void setDir(bool value);//设置方向
    float getresult(float in);//输入坐标，求另一个坐标
    point calintersection(line l);//输入直线 输出相交的点
    float getA() const;

    float getB() const;

    float getC() const;

private:
    void analysisstr(string str,string square,string one);
    float m_a;
    float m_b=0;
    float m_c=0;
    bool m_dir;//dir为ture时表示方程关于y轴对称
};

#endif // PAOWUXIAN_H
