#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[50005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a,a+n);
    int si=0,dou=0;
    for(int i = 0; i < n; i++)
    {
        if(i%2)
            dou += a[i];
        else
            si += a[i];
    }
    printf("%d\n", abs(dou-si));
    return 0;
}
