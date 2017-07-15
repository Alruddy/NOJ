#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <queue>
typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL> > pq;
LL ans[1600];

int main()
{
    while(!pq.empty()) pq.pop();
    pq.push(1);
    LL k = 1;
    ans[0] = 0;
    while(k <= 1590)
    {
        while(pq.top() == ans[k - 1]) pq.pop();
        LL x = pq.top();
        ans[k++] = x;
        pq.push(x*2);
        pq.push(x*3);
        pq.push(x*5);
    }
    while(scanf("%d", &k), k)
    {
        printf("%lld\n", ans[k]);
    }
    return 0;
}
