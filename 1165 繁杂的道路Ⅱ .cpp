#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200 + 5;
int x[N], y[N];
vector<int> mp[N];
int m,n;
int vis[N], ismatch[N];

int dfs(int u)
{
    for(int i = 0; i < mp[u].size(); i++)
    {
        int v = mp[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            if(ismatch[v] == -1 || dfs(ismatch[v]))
            {
                ismatch[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    memset(mp, 0, sizeof(mp));
    scanf("%d", &m);
    for(int i = 1; i <=m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if(x[u] > x[v])
            mp[v].push_back(u);
        else if(x[v] > x[u])
            mp[u].push_back(v);
    }
    memset(ismatch, -1, sizeof(ismatch));
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        cnt += dfs(i);
    }
    printf("%d", n - cnt);
    return 0;
}
