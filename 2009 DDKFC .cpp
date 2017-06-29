#include <cstdio>
#include <iostream>
using namespace std;
struct Point
{
    double x,y;
};
double r,x1,y1,x2,y2;
int n;
int t;
bool ok(Point a,double x,double y)
{
    return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y)<=r*r;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%lf%lf%lf%lf",&n,&r,&x1,&y1,&x2,&y2);
        Point p;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p.x,&p.y);
            if(ok(p,x1,y1)||ok(p,x2,y2))
                cnt++;
        }
        cout<<cnt<<endl;


    }




    return 0;
}
