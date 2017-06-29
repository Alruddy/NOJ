#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1000010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll ans=-1;
    int l=(n-1000)<0?0:(n-1000);
    for(int i=l;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            ans=max(ans,(ll)(a[i]&a[j])*(a[i]|a[j]));
    }
    cout<<ans<<endl;
    return 0;
}
