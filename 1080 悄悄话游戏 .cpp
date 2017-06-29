#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> G[10005];
bool vis[10005];
int n,t,e,q;
int init()
{
    for(int i=0;i<10005;i++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
}
bool bfs(int s)
{
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<G[u].size();i++)
            if(!vis[G[u][i]])
            {
                vis[G[u][i]]=1;
                q.push(G[u][i]);
            }
    }
    int flag=0;
    for(int i=0;i<n;i++)
        if(!vis[i]) {flag=1;break;}
    if(flag)
        return false;
    return true;
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&t);
        init();
        scanf("%d",&e);
        for(int i=0;i<e;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        bool sign=0;
        for(int i=0;i<n;i++)
            if(G[i].size()!=2&&G[i].size()!=0)
                {  sign=1;break; }
        if(sign) {printf("Failure\n"); continue;}
        if(bfs(t))
            printf("Success\n");
        else
            printf("Failure\n");
    }
    return 0;
}
