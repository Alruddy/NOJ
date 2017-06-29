#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int vis[505];
int n;
int mp[505][505];

int dfs(int pos,int hp)
{
    if(hp<=0)
    {
        return 0;
    }
    if(pos==n||hp>10000)/**É§²Ù×÷°¡*/
        return 1;
    vis[pos]=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&mp[pos][i]&&dfs(i,hp*2+mp[pos][i]))
        {
            return 1;
        }
    }
    vis[pos]=0;
    return 0;
}

LL solve()
{
    LL l=1,r=100000;
    while(l<r)
    {
        LL mid=(l+r)>>1;
        for(int i=0;i<=n;i++)
            vis[i]=0;
        if(dfs(1,mid)) r=mid;
        else l=mid+1;
    }
    return l;
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    cout<<solve()<<endl;





    return 0;
}
