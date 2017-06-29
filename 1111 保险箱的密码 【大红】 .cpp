#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
char src[250];
char dst[250];
int f[250];
int d[250][250];
int ans=0;

int dp(int l,int r)
{
    int &ans=d[l][r];
    if(ans!=-1) return ans;
    ans=0x3f3f3f3f;
    int st=l,en=r;
    while(st<=en&&src[st]==dst[st]) st++;
    if(st>en) return ans=0;
    while(en>=st&&src[en]==dst[en]) en--;
    if(st==en) return ans=1;

    for(int k=st+1;k<=en;k++)
    {
        int res=dp(st,k-1)+dp(k,en);
        int pl=k-1,pr=k;
        char chr=src[pr],chl=src[pl];
        while(pl>=st&&src[pl]==dst[pl]&&src[pl]==chr) pl--;
        while(pr<=en&&src[pr]==dst[pr]&&src[pr]==chl) pr++;
        if(pl>=st&&pr<=en&&src[pl]==src[pr])
            res--;

        ans=min(ans,res);
    }
    return ans;
}

void solve()
{
    memset(d,-1,sizeof(d));
    printf("%d\n",dp(1,strlen(src+1)));
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",src+1,dst+1);
        solve();
    }
    return 0;
}
