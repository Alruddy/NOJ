#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
struct Point
{
    double x,y;
};
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calculate(double a,double b,double c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
Point p[105];
int main()
{
    int n;
    double ans=-1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                double a=dist(p[i],p[j]);
                double b=dist(p[i],p[k]);
                double c=dist(p[j],p[k]);
                double area=calculate(a,b,c);
                ans=max(ans,area);
            }
        }
    }
   printf("%.1f",ans);


    return 0;
}
