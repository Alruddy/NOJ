#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    int a;
    int b;
};
bool cmp1(Node x,Node y)
{
    return x.a>y.a;
}
bool cmp2(Node x,Node y)
{
    return x.b>y.b;
}
bool cmp3(Node x,Node y)
{
    return x.id<y.id;
}
Node p[100010];
int vis[100010];
int pa[100010];
int pb[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p[i].id=i;
        cin>>p[i].a;
    }
    for(int j=0;j<n;j++)
        cin>>p[j].b;
    sort(p,p+n,cmp1);
    for(int i=0;i<n;i++)
    {
        pa[i]=p[i].id;
    }

    sort(p,p+n,cmp2);
    for(int i=0;i<n;i++)
    {
        pb[i]=p[i].id;
    }

    sort(p,p+n,cmp3);

    for(int i=0;i<n;i++)
        cout<<pa[i]<<" ";
    cout<<endl<<endl;
    for(int i=0;i<n;i++)
        cout<<pb[i]<<" ";
    cout<<endl;

    int ans=0;
    int j=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            while(vis[pb[k]]&&k<n) k++;
            ans-=p[pb[k]].b;
            vis[pb[k]]=1;
            cout<<pb[k]<<" ";
        }
        else
        {
            while(vis[pa[j]]&&j<n) j++;
            int r=k;
            while(vis[pb[r]]&&r<n) r++;
            int l=r+1;
            while(vis[pb[l]]&&l<n) l++;
            if(p[pb[r]].a-p[pb[l]].b>p[pa[j]].a-p[pb[r]].b)
            {
                ans+=p[pb[r]].a-p[pb[l]].b;
                vis[pb[r]]=1;
                cout<<pb[r]<<" ";
            }
            else
            {
                ans+=p[pa[j]].a-p[pb[r]].b;
                vis[pa[j]]=1;
                cout<<pa[j]<<" ";
            }

        }
        cout<<ans<<endl;

    }
    cout<<ans;

}
