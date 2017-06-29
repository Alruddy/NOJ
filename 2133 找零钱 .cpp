#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int v[55];
int cnt=0;
long long d[500];
int main()
{
    cout<<1-(1.0/(1<<10))<<endl;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&v[i]);
    d[0]=1LL;
    for(int i=0;i<m;i++)
    {
        for(int j=v[i];j<=n;j++)
        {
            d[j]+=d[j-v[i]];
        }
    }
    cout<<d[n];

    return 0;
}
