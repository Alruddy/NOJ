#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int mp[1000][1000];
int n;
int ans=0;

int dirx[]={0,1,0,-1,1,1,-1,-1};
int diry[]={1,0,-1,0,1,-1,1,-1};

void bfs(int x,int y,int color)
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    int tmp=x*1000+y;
    Q.push(tmp);
    mp[x][y]=color;
    while(!Q.empty())
    {
        int tmp=Q.front(); Q.pop();
        int i=tmp/1000,j=tmp%1000;
        for(int k=0;k<8;k++)
        {
            int nx=i+dirx[k];
            int ny=j+diry[k];
            if(nx<0||nx>=n||ny<0||ny>=n||mp[nx][ny]!=1) continue;
            mp[nx][ny]=color;
            int tmp=nx*1000+ny;
            Q.push(tmp);
        }
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch;
            scanf("%c",&ch);
            mp[i][j]=ch-'0';
        }
        getchar();
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp[i][j]==1)
            {
                ans--;
                bfs(i,j,ans);
            }
        }
    }

    printf("%d\n",-ans);
    return 0;
}
