#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i;
    ll ans=0LL;
    cin>>n;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
            ans=ans+i+n/i;
    }
    if(i*i==n)
        ans+=i;
    cout<<ans;


}
