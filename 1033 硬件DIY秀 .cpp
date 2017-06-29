#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Node
{
    int p;
    int v;
    Node(int _p,int _v):p(_p),v(_v) {}
};
vector<Node> G[1005];
map<string,int> mp;
const int INF=0x3f3f3f3f;
int cnt=0;
int n,m;
int ans=0;

bool cmp1(Node a,Node b)
{
    if(a.p==b.p)
        return a.v>b.v;
    return a.p<b.p;
}
bool check(int M)
{
    int sum=0;
    int i,j;
    for(i=0;i<cnt;i++)
    {
        int ches=INF;
        for(j=0;j<G[i].size();j++)
            if(G[i][j].v>=M) ches=min(ches,G[i][j].p);
        if(ches==INF)
            return false;
        sum+=ches;
    }
    if(sum>m) return false;
    return true;
}
int main()
{
    int q;
    cin>>q;
    char type[200],name[200];
    int p;
    int v;
    while(q--)
    {
        mp.clear();
        for(int i=0;i<1005;i++)
            G[i].clear();
        scanf("%d%d",&n,&m);
        int L=0,R=0;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s%s%d%d",type,name,&p,&v);
            if(!mp.count(type)) mp[type]=cnt++;
            G[mp[type]].push_back(Node(p,v));
            R=max(R,v);
        }
        while(L<R)
        {
            int M=L+(R-L+1)/2;
            if(check(M)) L=M;
            else R=M-1;
        }
        printf("%d\n",L);
    }

    return 0;
}
