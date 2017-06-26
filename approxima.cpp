#include "approxima.h"

approxima::approxima()
{

}


//计算圆与抛物线函数的公切线方程的斜率

float approxima::calpgqk(float deviation, point &p, paowuxian &fun, float step, int n)
{
    float k;//返回的k
    float dis;//切线离起点的距离
    float x=p.x()+n*step;//计算公切线的切点x
    float y=fun.getresult(x);//计算公切线的切点y
    point qpoint(x,y);//生成切点
    line qieline=fun.gettangent(qpoint);//获得切点的切线方程
    dis=qieline.calculatedis(p);//切线方程离起点p的距离
    cout<<"count2:"<<n<<endl;
    if(dis<deviation){//如果距离小于误差值，则n+1 继续递归下去
       n++;
       return calpgqk(deviation,p,fun,step,n);
    }else{
       k=qieline.k();//获取该切线的斜率
       return k;
    }
}

float approxima::caltgqk(float deviation, point &p, tuoyuan &fun, float step, int n, float &theta)
{
    float k;//返回的k
    float dis;//切线离起点的距离
    theta=fun.caltheta(p)+n*step;//计算公切线的切点角
    if(theta<=0){
        theta+=2*3.14;
    }
    if(theta>=2*3.14){
        theta-=2*3.14;
    }
    float x=fun.calx(theta);
    float y=fun.caly(theta);//计算公切线的切点y
    point qpoint;
    qpoint.setpoint(x,y);
    //point qpoint()=fun.pointoncurve(p);//生成切点
    line qieline=fun.gettangent(qpoint);//获得切点的切线方程
    dis=qieline.calculatedis(p);//切线方程离起点p的距离
    //cout<<"count2:"<<n<<" the: "<<theta<<endl;
    if(dis<deviation){//如果距离小于误差值，则n+1 继续递归下去
       n++;
       return caltgqk(deviation,p,fun,step,n,theta);
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

vector<point> approxima::calapprotuo(tuoyuan &tuo, float step, float deviation, bool dir)
{
    vector<point> vectorpoint;
    point startp=tuo.startpoint();
    point endp=tuo.endpoint();
    float starttheta=tuo.caltheta(startp);
    float endtheta=tuo.caltheta(endp);
    float theta=starttheta;
    cout<<starttheta<<"end:"<<endtheta<<endl;
    point nextp,p;
    p=startp;
    if(dir){//true 顺时针 theta 减少
        step=-abs(step);
    }else{
        step=abs(step);
    }
    int i=0;
    //一共四种情况
    while ((dir&&endtheta<starttheta&&endtheta<=theta&&theta<=starttheta)||
           (dir&&endtheta>starttheta&&(!(endtheta>theta&&theta>starttheta)))||
           ((!dir)&&endtheta>starttheta&&(endtheta>=theta&&theta>=starttheta))||
           ((!dir)&&endtheta<starttheta&&(!(endtheta<theta&&theta<starttheta)))
           )
    {
        //||(dir&&(!(endtheta>=theta&&theta>=starttheta)))||
       //
        i++;
        float k=caltgqk(deviation,p,tuo,step,1,theta);//计算公切线 抛物线公式
        line jiaol(p,k);//过该点以公切线的斜率
        nextp=tuo.calintersection(jiaol,p,tuo);//计算交点
        cout<<"x:"<<nextp.x()<<"y:"<<nextp.y()<<" the:  "<<theta<<endl;
        vectorpoint.push_back(p);//添加交点
        //更新下次迭代点
        p=nextp;
    }
    vectorpoint.push_back(p);//添加交点
    return vectorpoint;
}
