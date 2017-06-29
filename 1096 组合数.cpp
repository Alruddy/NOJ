#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL C(int m,int n)
{
    LL ans=1LL;
    for(int i=1,j=n;i<=m;i++,j--)
        ans=ans*j/i;
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%lld\n",C(m,n));
    }
    return 0;
}
