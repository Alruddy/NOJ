#include <cstdio>
#include <iostream>
using namespace std;
int t,n,m,i;
int a[1000010];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<n;i++)
        {
            if(a[i]==m)
            {
                printf("Yes\n");
                break;
            }
        }
        if(i==n)
            printf("No\n");
    }





}
