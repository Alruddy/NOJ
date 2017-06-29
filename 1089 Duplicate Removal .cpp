#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int vis[105];
int main()
{
    int n;
    while(cin>>n,n)
    {
        int tmp,pre;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {

            scanf("%d",&tmp);
            if(i==0)
            {
                printf("%d ",tmp);
                pre=tmp;
                continue;
            }
            if(tmp!=pre)
            {
                printf("%d ",tmp );
            }
            pre=tmp;
        }
        printf("$\n");
    }
    return 0;
}
