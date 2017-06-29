#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int vis[1000010];
int main()
{
    int n;
    cin>>n;
    memset(vis,0,sizeof(vis));
    int cnt=n;
    int pos=0;
    while(cnt)
    {
        while(vis[pos]) pos=(pos+1)%n;
        vis[pos]=1;
        if(cnt!=n) printf(" ");
        printf("%d",pos+1);
        cnt--;
        if(!cnt) break;
        while(vis[pos]) pos=(pos+1)%n;
        pos=(pos+1)%n;
    }





}
