#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int ind[105];
int main()
{
    int t,n,k,i,u,v,ok;
    scanf("%d",&t);
    while(t--)
    {
        memset(ind,0,sizeof(ind));
        ok=1;
        scanf("%d%d",&n,&k);
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&u,&v);
            ind[u]++;
            ind[v]++;
        }
        for(i=1;i<=n;i++)
        {
            if(ind[i]%2) {ok=0;break;}
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
