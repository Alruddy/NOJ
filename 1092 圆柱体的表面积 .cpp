#include <stdio.h>
#include <math.h>
const double pi=acos(-1.0);
int main()
{
    double r,h;
    int kase=1;
    while(scanf("%lf%lf",&r,&h)==2,r||h)
    {
        printf("Case %d:%.2f\n",kase++,r*r*pi*2+2*pi*r*h);
    }
    return 0;
}
