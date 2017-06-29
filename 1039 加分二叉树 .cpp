#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
LL d[50][50];
int ans[50];
int p=0;
void print_ans(int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        ans[p++]=l;
        return;
    }
    for(int k=l;k<r;k++)
    {
        if(d[k][k]+d[l][k-1]*d[k+1][r]==d[l][r])
        {
            ans[p++]=k;
            print_ans(l,k-1);
            print_ans(k+1,r);
            return;
        }
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        p=0;
        for(int i=0;i<40;i++)
            for(int j=0;j<40;j++)
                d[i][j]=1;
        for(int i=1;i<=n;i++)
            scanf("%d",&d[i][i]);
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+len-1;
                for(int k=i;k<j;k++)
                    d[i][j]=max(d[i][k-1]*d[k+1][j]+d[k][k],d[i][j]);
            }
        }
        cout<<d[1][n]<<endl;
        print_ans(1,n);
        for(int i=0;i<p;i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
    }
}
