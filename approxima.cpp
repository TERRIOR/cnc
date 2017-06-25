#include "approxima.h"

approxima::approxima()
{

}


//计算圆与抛物线函数的公切线方程的斜率
float approxima::calpgqk(float deviation, point &p, paowuxian &pao,float step,int n)
{
    float k;//返回的k
    float dis;//切线离起点的距离
    float x=p.x()+n*step;//计算公切线的切点x
    float y=pao.getresult(x);//计算公切线的切点y
    point qpoint(x,y);//生成切点
    line qieline=pao.gettangent(qpoint);//获得切点的切线方程
    dis=qieline.calculatedis(p);//切线方程离起点p的距离
    cout<<"count2:"<<n<<endl;
    if(dis<deviation){//如果距离小于误差值，则n+1 继续递归下去
       n++;
       return calpgqk(deviation,p,pao,step,n);
    }else{
       k=qieline.k();//获取该切线的斜率
       return k;
    }
}

vector<point> approxima::calappropao(paowuxian &pao,float step,float deviation)
{
    vector<point> vectorpoint;
    point p=pao.startpoint();
    cout<<p.x()<<p.y()<<endl;
    point nextp;
    if(pao.endpoint().x()>pao.startpoint().x()){//判断起点终点的关系，决定逼近方向
        step=abs(step);
    }else{
        step=-abs(step);
    }
    int i=0;
    //直到当前点不在起点终点之间
    while ((p.x()<=pao.startpoint().x()&&p.x()>=pao.endpoint().x())
           ||(p.x()>=pao.startpoint().x()&&p.x()<=pao.endpoint().x())) {

        i++;
        float k=calpgqk(deviation,p,pao,step,1);//计算公切线 抛物线公式
        line jiaol(p,k);//过该点以公切线的斜率
        nextp=pao.calintersection(jiaol,p,pao);//计算交点
        cout<<"x:"<<nextp.x()<<"y:"<<nextp.y()<<endl;
        vectorpoint.push_back(p);//添加交点
        //更新下次迭代点
        p=nextp;
    }
    vectorpoint.push_back(p);//添加交点
    return vectorpoint;
}

vector<point> approxima::calapprotuo(tuoyuan tuo,float step,float deviation)
{
    vector<point> vectorpoint;
    return vectorpoint;
}
