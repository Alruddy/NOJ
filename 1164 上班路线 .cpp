#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long LL;

int f[60];
int C(int n, int m, int mod)
{
    LL ans = 1;
    for(int i = 1; i <= m; i++)
        ans = (ans * ((n - i + 1) * f[i] % mod)) % mod ;
    return (int)ans;
}

int quick_mod(int a, int n, int mod)
{
    int ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int mod = 9901;
    for(int i = 1; i <= 50; i++)
    {
        f[i] = quick_mod(i, mod - 2, mod);
    }

    int n,m;
    scanf("%d%d", &n, &m);
    printf("%d\n", C(n+m, m, mod));
    return 0;
}
