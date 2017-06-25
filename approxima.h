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
    vector<point> calapprotuo(tuoyuan tuo,float step,float deviation);
    float calpgqk(float deviation,point &p,paowuxian &pao,float step,int n);
};

#endif // APPROXIMA_H
