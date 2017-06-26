#ifndef APPROXIMA_H
#define APPROXIMA_H
#include "point.h"
#include "line.h"
#include "paowuxian.h"
#include "tuoyuan.h"
#include <iostream>
#include <vector>
using namespace std;

class approxima:public curve
{
public:
    approxima();
    vector<point> calappropao(paowuxian &pao,float step,float deviation);
    //dir is true:顺时针 false:逆时针
    vector<point> calapprotuo(tuoyuan &tuo,float step,float deviation,bool dir);
    float calpgqk(float deviation,point &p,paowuxian &fun,float step,int n);
    float caltgqk(float deviation,point &p,tuoyuan &fun,float step,int n,float &theta);
};

#endif // APPROXIMA_H
