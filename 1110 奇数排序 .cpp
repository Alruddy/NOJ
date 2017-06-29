#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100010];
int n;
vector<int> ind;
vector<int> data;
int q;
void init()
{
    ind.clear();
    data.clear();
}
int main()
{
    scanf("%d",&q);
    int kase=0;
    while(q--)
    {
        init();
        printf("Case %d:\n",++kase);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2)
            {
                data.push_back(a[i]);
                ind.push_back(i);
            }
        }
        sort(data.begin(),data.end());

        int pos=0;
        for(int i=0;i<n;i++)
        {
            if(i) printf(" ");
            if(i==ind[pos])
            {
                printf("%d",data[pos++]);
            }
            else
                printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
