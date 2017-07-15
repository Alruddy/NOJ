#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int T,n,m;
int a[250][250];
int ind[250];
int topo[250];
int earliest[250];
int lastest[250];

void topsort()
{
    int k = 0;
    int vis[250];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n + 1; i++)
    {
        int j = 0;
        for(j = 0; j <= n + 1; j++)
        {
            if(ind[j] == 0 && !vis[j])
            {
                vis[j] = 1;
                topo[k++] = j;
                break;
            }
        }
        for(int s = 0; s <= n + 1; s++)
        {
            if(a[j][s] < INF)
            {
                ind[s]--;
            }
        }
    }

}

int main()
{
    scanf("%d", &T);
    while(T--)
    {

        scanf("%d%d", &n, &m);
        memset(a, 0x3f, sizeof(a));
        memset(ind, 0, sizeof(ind));
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            a[u][v] = w;
            ind[v]++;
        }
        topsort();
        earliest[0] = 0;
        for(int i = 1; i <= n+1; i++)
        {
            int cv = topo[i];
            earliest[cv] = 0;
            for(int u = 0; u <= n+1; u++)
                if(a[u][cv] < INF)
                    earliest[cv] = max(earliest[cv], earliest[u] + a[u][cv]);
        }
        lastest[n+1]=earliest[n+1];
        for(int i = n; i >= 0; i--)
        {
            int cu = topo[i];
            lastest[cu] = INF;
            for(int v = 0; v <= n+1; v++)
                if(a[cu][v] < INF)
                    lastest[cu] = min(lastest[cu], lastest[v] - a[cu][v]);
        }

        /*for(int i = 0; i <= n+1; i++)
            cout<<earliest[i]<<" ";
        cout<<endl;
        for(int i = 0; i <= n+1; i++)
            cout<<lastest[i]<<" ";
        cout<<endl;*/
        for(int i = 0; i <= n+1; i++)
        {
            for(int j = n+1; j >= i + 1; j--)
            {
                if(lastest[j] - earliest[i] == a[i][j])
                    printf("(%d,%d)",i,j);
            }
        }
        printf("\n");
    }



}
