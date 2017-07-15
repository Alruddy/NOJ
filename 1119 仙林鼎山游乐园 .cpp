#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int ind[60];
int vis[60];
int mp[60][60];
int n, e;

bool TopSort()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        int index = -1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && ind[j] == 0)
            {
                index = j;
                break;
            }
        }
        if(index == -1)
            return false;
        vis[index] = 1;

        for(int j = 0; j < n; j++)
        {
            if(mp[index][j] == 1)
            {
                ind[j]--;
            }
        }
    }
    return true;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(mp, 0, sizeof(mp));
        memset(ind, 0, sizeof(ind));
        scanf("%d%d", &n, &e);
        for(int i = 0; i < e; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            mp[u][v] = 1;
            ind[v]++;
        }

        printf("%s\n", TopSort() ? "NO" : "YES");
    }
    return 0;
}
