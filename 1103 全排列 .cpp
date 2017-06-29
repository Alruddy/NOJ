#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int a[20];

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    do
    {
        print(a,n);
    }while(next_permutation(a,a+n));
    return 0;
}
