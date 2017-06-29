#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=10;
char mp[maxn+2][maxn+2];
int hsh[999999+5];
int cx,cy,mx,my;
int dirx[]={-1,0,1,0};
int diry[]={0,1,0,-1};
int main()
{
    for(int i=0;i<maxn;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            if(mp[i][j]=='C')
            {
                cx=i;cy=j;
                mp[i][j]='.';
            }
            else if(mp[i][j]=='M')
            {
                mx=i;my=j;
                mp[i][j]='.';
            }
        }
    }

    memset(hsh,0,sizeof(hsh));
    int dc,dm;
    dc=dm=0;
    int tmp=cx*1000+cy*100+mx*10+my+dc*100000+dm*10000;
    int cnt=0;
    hsh[tmp]=1;
    int flag=0;
    while(1)
    {
        int tmp=cx*1000+cy*100+mx*10+my;
        hsh[tmp]=1;
        if(cx==mx&&cy==my)
        {
            flag=0;
            break;
        }
        cnt++;
        int ncx=cx+dirx[dc];
        int ncy=cy+diry[dc];
        if(ncx<0||ncx>=maxn||ncy<0||ncy>=maxn||mp[ncx][ncy]=='*')
        {
            dc=(dc+1)%4;
        }
        else
        {
            cx=ncx;
            cy=ncy;
        }
        int nmx=mx+dirx[dm];
        int nmy=my+diry[dm];
        if(nmx<0||nmx>=maxn||nmy<0||nmy>=maxn||mp[nmx][nmy]=='*')
        {
            dm=(dm+1)%4;
        }
        else
        {
            mx=nmx;
            my=nmy;
        }
        tmp=cx*1000+cy*100+mx*10+my+dc*100000+dm*10000;
        if(hsh[tmp])
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<"-1"<<endl;
    }
    else
        cout<<cnt;

    return 0;
}
