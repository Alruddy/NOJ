#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxmod = 16;
const int len = 32;
typedef unsigned int uint;
uint a[len];
uint b[len];
uint cal(uint x, uint y, int mod)
{
    return (x+y)%mod;
}

void solve(uint x, int base, uint b[])
{
    for(int i = 0; i < len; i++)
        b[i] = 0;
    if(x == 0) return;
    uint c[len][maxmod];
    uint d[len],w[len];
    uint tmp = x, n = 0;
    while(tmp)
    {
        d[n++] = tmp%base;
        tmp /= base;
    }
    n--;
    w[0] = 1;
    for(int i = 1; i<=n; i++)
        w[i] = w[i-1] * base;
    memset(c, 0, sizeof(c));
    for(int i = n; i >=0; i--)
    {
        for(int j = 0; j < d[i]; j++)
            c[i][j]=cal(c[i][j], w[i], base);
        c[i][d[i]]=cal(c[i][d[i]],x%w[i]+1,base);
        for(int j=i-1;j>=0;j--)
        {
            for(int k=0;k<base;k++)
                c[j][k]=cal(c[j][k],d[i]*w[i-1],base);
        }
    }
    for(int i=n;i>=0;i--)
    {
        b[i]=0;
        for(int j=0;j<base;j++)
            b[i]=cal(b[i],c[i][j]*j,base);
    }
}
int main()
{
    int T;
    uint x,y,ans,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        memset(a,0,sizeof(a));
        while(n--)
        {
            cin>>x>>y;
            solve(y,m,b);
            for(int i=0;i<len;i++)
                a[i]=(a[i]+b[i])%m;
            if(x>0)
            {
                solve(x-1,m,b);
                for(int i=0;i<len;i++)
                    a[i]=(a[i]+m-b[i])%m;
            }
        }
        ans=0;
        for(int i=len-1;i>=0;i--)
            ans=ans*m+a[i];
        cout<<ans<<endl;
    }
    return 0;
}
