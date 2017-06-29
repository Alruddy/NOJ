#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int q,e,m,k;
int fa[205];
struct Edge
{
    int u;
    int v;
    int w;
    Edge(){}
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w) {}
};
vector<Edge> vt;
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int Find(int x)
{
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void init()
{
    vt.clear();
    for(int i=0;i<205;i++)
        fa[i]=i;
}
void kruskal()
{
    sort(vt.begin(),vt.end(),cmp);
    int cost=0,cnt=1;
    for(int i=0;i<e;i++)
    {
        int u=vt[i].u,v=vt[i].v;
        int x=Find(u),y=Find(v);
        if(x!=y)
        {
            fa[x]=y;
            cost+=vt[i].w;
            cnt++;
        }
        if(cnt>=m)
            break;
    }
    if(cnt<m)
        printf("Impossible\n");
    else
        printf("%d\n",cost);
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        init();
        scanf("%d",&m);
        scanf("%d%d",&e,&k);
        for(int i=0;i<e;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w>=24||w<0) continue;
            vt.push_back(Edge(u,v,w));
        }
        e=vt.size();
        kruskal();
    }
    return 0;
}
