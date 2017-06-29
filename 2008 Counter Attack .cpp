#include <cstdio>
#include <iostream>
using namespace std;
long long f[55];
int main()
{
    f[1]=2;
    f[2]=3;
    for(int i=3;i<=51;i++)
        f[i]=f[i-1]+f[i-2];
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<"\n";
    }



}
