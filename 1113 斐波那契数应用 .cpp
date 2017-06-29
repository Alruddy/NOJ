#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL f[100]={0,1,2};
int b[100];
int main()
{
    for(int i=3;i<60;i++)
        f[i]=f[i-1]+f[i-2];
    int q;
    cin>>q;
    while(q--)
    {
        int x,pos=0;
        scanf("%d",&x);
        memset(b,0,sizeof(b));
        for(int j=59;j>=1;j--)
        {
            if(x>=f[j]&&x<f[j+1])
            {
                x-=f[j];
                pos=max(j,pos);
                b[j]=1;
            }
        }
        LL ans=0;
        for(int i=2;i<=pos;i++)
            ans=ans+b[i]*f[i-1];
        cout<<ans<<endl;

    }



}
