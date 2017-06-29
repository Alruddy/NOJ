#include <cstdio>
#include <iostream>
using namespace std;
int q;
double x1,y1;
double x2,y2;
double x3,y3;
double hls(double a,double b,double c,double d)
{
    return a*d-b*c;
}
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;

        double a=y1-y2,b=y3-y1;
        double c=x2-x1,d=x1-x3;
        double e=x2-x3,f=y2-y3;
        double l1=hls(e,b,f,d)/hls(a,b,c,d);
        double x=x3+a*l1;
        double y=y3+c*l1;
        printf("%.3f %.3f\n",x,y);
    }
    return 0;
}
