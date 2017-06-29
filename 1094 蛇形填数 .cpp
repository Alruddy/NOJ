#include <stdio.h>
#include <iostream>
using namespace std;
int mp[100][100];
int n;
int dirx[]={1,0,-1,0};
int diry[]={0,-1,0,1};
int main()
{
    int n;
    scanf("%d",&n);
    int sx=1,sy=n;
    mp[sx][sy]=1;
    int k=1,d=0;
    while(k<n*n)
    {
        int nx=sx+dirx[d];
        int ny=sy+diry[d];
        if(nx<1||nx>n||ny<1||ny>n||mp[nx][ny]>0)
        {
            d=(d+1)%4;
            nx=sx+dirx[d];
            ny=sy+diry[d];
        }
        k++;
        mp[nx][ny]=k;
        sx=nx;sy=ny;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%5d",mp[i][j]);
        }
        printf("\n");
    }


    return 0;
}
