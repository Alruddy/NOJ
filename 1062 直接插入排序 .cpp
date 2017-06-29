#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n,r;
int a[500];



int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    puts("Source:");
    r=0;
    printf("(");
    for(int i=0;i<=r;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf(")");
    for(int i=r+1;i<n;i++)
    {
        printf(" ");
        printf("%d",a[i]);
    }
    puts("");
    puts("Insert Sort:");

    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int tmp=a[i];
        while(j>=0&&a[j]>tmp)
        {
            a[j+1]=a[j];
            j--;
        }
        j++;
        a[j]=tmp;
        r++;
        printf("(");
        for(int k=0;k<=r;k++)
        {
            if(k) printf(" ");
            printf("%d",a[k]);
        }
        printf(")");
        for(int k=r+1;k<n;k++)
            printf(" %d",a[k]);
        puts("");
    }

    puts("Result:");
    printf("(");
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf(")");
    return 0;
}
