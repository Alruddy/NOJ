#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int vis[500005]={0};
int prime[500005]={0};
int k,n;
int cal(int x)
{
    int m = sqrt(x);
    int ans = 1,cnt = 0;
    for(int i = 0; prime[i]*prime[i] <= n; i++)
    {
        cnt = 1;
        while(x%prime[i] == 0)
        {
            x /= prime[i];
            cnt++;
        }
        ans = ans * cnt;
    }
    if(x != 1)
        ans *= 2;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for(int i = 4; i <= 500000; i+=2)
        vis[i] = 1;
    prime[0]=2;
    k=1;
    for(int j = 3; j*j <= 500000; j+=2)
    {
        if(!vis[j])
        {
            prime[k++]=j;
            for(int s = j*j; s <= 500000; s += 2*j)
                vis[s] = 1;
        }
    }
    for(int i = sqrt(500000.0); i <= 500000; i+=2)
        if(!vis[i])
            prime[k++] = i;
    cin>>n;
    int ans = 1,ansy = 1;
    for(int i = 2; i <= n; i ++)
    {
        int tmp = cal(i);
        if(ansy < tmp)
        {
            ansy = tmp;
            ans = i;
        }
    }
    cout<<ans<<" "<<ansy<<endl;
    return 0;
}
