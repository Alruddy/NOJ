#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    double s1x,s1y,e1x,e1y;
    double s2x,s2y,e2x,e2y;
    while(cin>>s1x>>s1y>>e1x>>e1y>>s2x>>s2y>>e2x>>e2y)
    {
        if(s1x>e1x)
        {
            swap(s1x,e1x);
            swap(s1y,e1y);
        }
        if(s2x>e2x)
        {
            swap(s2x,e2x);
            swap(s2y,e2y);
        }
        if(s1x==e1x&&(s2x<=s1x&&e2x>=s1x))
        {
            puts("yes");
            continue;
        }
        if(s2x==e2x&&(s1x<=s2x&&e1x>=s2x))
        {
            puts("yes");
            continue;
        }
        if(s1x==e1x||s2x==e2x)
        {
            puts("no");
            continue;
        }

        if(s1x<=e2x&&s2x<=e1x)
        {

            double k1=(e1y-s1y)/(e1x-s1x);
            double k2=(e2y-s2y)/(e2x-s2x);

            double x1,x2;

            x1=max(s1x,s2x);
            x2=min(e1x,e2x);

            double flag1=0,flag2=0;

            flag1=(k1*(x1-s1x)+s1y)-(k2*(x1-s2x)+s2y);
            flag2=(k1*(x2-s1x)+s1y)-(k2*(x2-s2x)+s2y);

            if(flag1*flag2<=0)
            {
                puts("yes");
                continue;
            }
        }
        puts("no");


    }



    return 0;
}
