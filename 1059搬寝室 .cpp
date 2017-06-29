#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[5005];
int vis[1000005];
int b[1000050];
int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    int mmax=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int c=(a[j]-a[i]);
            vis[c]=1;
        }
    }
    for(int i=n;i<=a[n-1];i++)
    {
        if(vis[i]==0)
        {
            memset(b,0,sizeof(b));
            int flag=1;
            for(int j=0;j<n;j++)
            {
                int cur=a[j]%i;
                if(b[cur])
                {
                    flag=0;
                    break;
                }
                else
                    b[cur]=1;
            }
            if(flag)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}

