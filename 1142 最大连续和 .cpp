#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> vt;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        vt.clear();
        for(int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            vt.push_back(a);
        }

        int maxans = -INF;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum = sum >= 0 ? sum + vt[i] : vt[i];
            maxans = max(maxans, sum);
        }
        printf("%d\n", maxans);
    }
    return 0;
}
