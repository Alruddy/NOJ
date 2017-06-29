#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int INF=0x3f3f3f3f;
int q,n,m;
int G[205][205];
int early[205],last[205];
int ind[205],tapo[205];
void Indegree()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j]!=INF)
                ind[j]++;
        }
    }
}
void Taposort()
{
    int k=0;
    int pos=0;
    while(k<n)
    {
        for(int i=0;i<n;i++)
            if(ind[i]==0)
            {
                ind[i]--;
                tapo[k++]=i;
            }
        int u=tapo[pos];
        pos++;
        for(int i=0;i<n;i++)
            if(G[u][i]!=INF)
                ind[i]--;
    }
}
void init()
{
    memset(G,0x3f,sizeof(G));
    memset(tapo,0,sizeof(tapo));
    memset(ind,0,sizeof(ind));
    memset(early,0,sizeof(early));
    memset(last,0x3f,sizeof(last));
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&m);
        init();
        memset(G,0x3f,sizeof(G));
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=w;
        }
        Indegree();
        Taposort();
        for(int i=0;i<n;i++)
        {
            int v=tapo[i];
            for(int j=0;j<n;j++)
            {
                if(G[j][v]!=INF)
                {
                    early[v]=max(early[j]+G[j][v],early[v]);
                }
            }
        }

        last[n-1]=early[n-1];
        for(int i=n-1;i>=0;i--)
        {
            int u=tapo[i];
            for(int j=0;j<n;j++)
            {
                if(G[u][j]!=INF)
                {
                    last[u]=min(last[j]-G[u][j],last[u]);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(early[i]==last[i])
                printf("%d ",i);
        }
        puts("");



    }


    return 0;
}
