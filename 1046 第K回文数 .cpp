#include <iostream>
#include <stdio.h>
using namespace std;
int f[12]={0,9,9,90,90,900,900,9000,9000,90000,90000,900000};
int j[12]={0,1,10,100,1000,10000,100000,100000,1000000,10000000,100000000,1000000000};
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,i;
        scanf("%d",&n);
        n--;
        for(i=1;i<=9;i++)
        {
            if(n<f[i])
                break;
            n=n-f[i];
        }
        int k=(i+1)/2;
        printf("%d",n=n+j[k]);
        if(i%2==0) {printf("%d",n%10);}
        n/=10;
        while(n)
        {
            printf("%d",n%10);
            n/=10;
        }
        printf("\n");
    }
    return 0;
}
