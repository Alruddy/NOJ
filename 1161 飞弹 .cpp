#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[1010];
int h[1010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i <n; i++)
        scanf("%d", &h[i]);
    for(int i = n-1; i >= 0; i--)
    {
        dp[i] = 1;
        for(int j = n-1; j >= i+1; j--)
            if(h[i] > h[j])
                dp[i] = max(dp[i], dp[j]+1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;

}
