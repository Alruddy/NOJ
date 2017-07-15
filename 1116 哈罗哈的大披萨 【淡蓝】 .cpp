#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int m, n, x;
double p, a, y;
double dp[1<<16 | 1];
double zhekou[1<<16 | 1][16];
double toarea[1<<16 | 1];
int bit[1 << 16 | 1];

struct Pizza
{
    double p;
    double a;
    double Coupon[16];
};
Pizza pizza[16];
inline int lowbit(int i)
{
    return i&(-i);
}
void read()
{
    for(int i = 0; i < m; i++)
    {
        scanf("%lf%lf%d", &p, &a, &n);
        pizza[i].p = p;
        pizza[i].a = a;
        for(int j = 0; j < n; j++)
        {
            scanf("%d%lf", &x, &y);
            pizza[i].Coupon[x-1] = y;
        }
    }
}

void solve()
{
    int maxs = 1 << m;
    for(int i = 0; i < m; i++)
        bit[1 << i] = i;

    toarea[0] = 0;
    for(int i = 1; i < maxs; i++)
    {
        int id = bit[lowbit(i)];
        toarea[i] = toarea[i - lowbit(i)] + pizza[id].a;
    }

    dp[0] = 0;
    for(int s = 1; s < maxs; s++)
        dp[s] = 1e9;

    for(int s = 0; s < maxs; s++)
    {
        for(int i = 0; i < m; i++)
        {
            if((1 << i) & s) continue;
            zhekou[s][i] = 1.0;
            if(s)
            {
                int lowb = lowbit(s);
                int id = bit[lowb];
                zhekou[s][i] = zhekou[s ^ lowb][i] * (100 - pizza[id].Coupon[i]) / 100.0;
            }
            dp[s ^ (1<<i)] = min(dp[s ^ (1<<i)], dp[s] + zhekou[s][i]*pizza[i].p);
        }
    }
    double ans = 1e10;
    for(int s = 0; s < maxs; s++)
    {
        ans=min(ans, dp[s] * 1.0 / toarea[s]);
    }
    printf("%.4f\n", ans);
}

int main()
{
    while(scanf("%d", &m) == 1, m)
    {
        read();
        solve();
    }
    return 0;
}
