#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Node
{
    int st;
    int en;
    int w;
    Node(int _st, int _en, int _w):st(_st), en(_en), w(_w) {}
};
bool cmp(Node a, Node b)
{
    return a.en < b.en;
}
vector<Node> Job;
int n, f = 0;
int dp[1000010];
int read()
{
    int st, en, w;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &st, &en, &w);
        f=max(en, f);
        Job.push_back(Node(st, en, w));
    }
    sort(Job.begin(), Job.end(), cmp);
}

int main()
{
    read();
    for(int i = 0; i < n; i++)
    {
        int l = 0, r = i;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(Job[m].en <= Job[i].st) l = m + 1;
            else r = m - 1;
        }
        dp[i] = max(dp[i-1], dp[l - 1] + Job[i].w);
    }
    cout << dp[n - 1] << endl;
    return 0;
}

