#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;
double d;
int n;
double r[20];

double calheight(int i, int j)
{
    double l = r[i] + r[j];
    double a = d - l;
    return sqrt(l*l - a*a);
}

double dp[1 << 16 |1][16]; //状态status下  i在最上面的最小值
//dp[status][j]=dp[status ^ (1 << j)][i] - r[i] + cal(i,j) + r[j] ;

bool read()
{
    scanf("%d%lf", &n, &d);
    if(n == 0 && d == 0) return false;
    for(int i = 0; i < n; i++)
        scanf("%lf", &r[i]);
    return true;
}

int solve()
{
    memset(dp, 0, sizeof(dp));
    for(int s = 0; s < (1 << n); s++)
    {
        for(int i = 0; i < n; i++)
        {
            if(s & (1<<i)) continue;
            if(s)
                dp[s ^ (1<<i)][i] = 1000000000;
            else
                dp[s ^ (1<<i)][i] = r[i] + r[i];
            for(int j = 0; j < n; j++)
            {
                if(s & (1<<j))
                {
                    dp[s ^ (1 << i)][i] = min(dp[s ^ (1<<i)][i], dp[s][j] - r[j] + r[i] + calheight(i,j));
                }
            }
        }
    }
    double ans = 1000000000;
    for(int i = 0; i < n; i ++)
    {
        ans =min(ans, dp[((1 << n) - 1)][i]);
    }
    printf("%.0f\n", (ans));

}

int main()
{
    while(read())
    {
        solve();
    }
    return 0;
}
