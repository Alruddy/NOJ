#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

bool vis[2001000];
const int offen = 1000000;
int main()
{
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        tmp += offen;
        vis[tmp] = true;
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        tmp += offen;
        if(vis[tmp])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
