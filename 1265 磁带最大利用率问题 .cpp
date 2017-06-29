#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n,m;
int cnt=0;
int ans[100005];
struct Node
{
    int id;
    LL vl;
}v[100005];
bool cmp(Node a,Node b)
{
    return a.vl<b.vl;
}
bool cmp1(Node a,Node b)
{
    return a.id<b.id;
}
int main()
{

    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].vl;
        v[i].id=i;
    }
    sort(v,v+n,cmp);
    LL s=0;
    for(int i=0;i<n;i++)
    {
        if(s+v[i].vl<=m)
        {
            s+=v[i].vl;
            cnt++;
        }
        else
            break;
    }
    cout<<cnt<<" ";
    LL mmax=s;
    int indf=-1;
    for(int i=0;i<cnt;i++)
        ans[i]=i;



    for(int i=cnt;i<n;i++)
    {
        indf=-1;
        for(int j=0;j<cnt;j++)
        {
            if(s-v[ans[j]].vl+v[i].vl<=m)
            {
                if(mmax<s-v[ans[j]].vl+v[i].vl)
                {
                    mmax=s-v[ans[j]].vl+v[i].vl;
                    indf=j;
                }
            }
        }
        if(indf!=-1)
        {
            s=mmax;
            ans[indf]=i;
        }
        else
            break;
    }



    cout<<s<<endl;
    for(int i=0;i<cnt;i++)
        ans[i]=v[ans[i]].id;
    sort(ans,ans+cnt);
    sort(v,v+n,cmp1);
    for(int i=0;i<cnt;i++)
        cout<<v[ans[i]].vl<<" ";
    return 0;
}
