#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int d[1005][40][2];
int t,k;
int main()
{
    cin>>t>>k;
    memset(d,0,sizeof(d));
    for(int i=1;i<=t;i++)
    {
        int s;
        cin>>s;
        s=s%2;
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            {
                d[i][j][1]=d[i-1][j][1]+s;
                d[i][j][0]=d[i-1][j][0];
            }
            if(j>=1)
            {
                d[i][j][s]=max(d[i-1][j-1][s^1],d[i-1][j][s])+1;
                d[i][j][s^1]=max(d[i-1][j][s^1],d[i-1][j-1][s]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++)
        ans=max(d[t][i][0],d[t][i][1]);
    cout<<ans;




    return 0;
}
