#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n;
int a[500];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    puts("Source:");
    printf("(");
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf(")\n");

    puts("Bubble Sort:");
    int last=0;
    for(int i=n-1;i>0;i=last)
    {
        last=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                last=j;
            }
        }
        i=last;
        printf("(");
        for(int j=0;j<=i;j++)
        {
            if(j) printf(" ");
            printf("%d",a[j]);
        }
        printf(")");
        for(int j=i+1;j<n;j++)
            printf(" %d",a[j]);
        puts("");
    }

    puts("Result");
    printf("(");
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf(")");


    return 0;
}


