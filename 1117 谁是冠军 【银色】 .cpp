#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
typedef long long LL;
//set<LL> s[100];
inline int cal(LL x)
{
    int ans = 0;
    while(x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int main()
{
    LL n, cnt, ans = 0;
    scanf("%lld", &n);
    for(LL i = 1; i <= n; i++)
    {
        cnt = cal(i);
        if(i % cnt == 0)
            ans++;
    }
    printf("%lld\n", ans);
    return 0;
}
