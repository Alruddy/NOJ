#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> pii;
int fa[100010];

int Find(int x)
{
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
        fa[xx]=yy;
}
vector<int> G[100010];
int x[100010],y[100010];
char Q[100010][2];
int main()
{
    for(int i=0;i<100010;i++)
        fa[i]=i;
    int n,m,u,v,q;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        scanf("%s%d%d",Q[i],&x[i],&y[i]);
        if(Q[i][0]=='D')
        {
            for(vector<int>::iterator it=G[x[i]].begin();it!=G[x[i]].end();it++)
            {
                if(*it==y[i])
                {
                    G[x[i]].erase(it);
                    break;
                }
            }
            for(vector<int>::iterator it=G[y[i]].begin();it!=G[y[i]].end();it++)
            {
                if(*it==x[i])
                {
                    G[y[i]].erase(it);
                    break;
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
            Union(i,G[i][j]);
    }
    char ans[100010];
    for(int i=q-1;i>=0;i--)
    {
        if(Q[i][0]=='Q')
        {
            int xx=Find(x[i]);
            int yy=Find(y[i]);
            if(xx==yy)
                ans[i]='C';
            else
                ans[i]='D';
        }
        else
            Union(x[i],y[i]);
    }
    for(int i=0;i<q;i++)
        if(Q[i][0]=='Q')
            printf("%c\n",ans[i]);

}
