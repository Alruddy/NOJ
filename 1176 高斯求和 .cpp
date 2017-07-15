#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
typedef long int LL;

int main()
{
    LL n;
    scanf("%ld", &n);
    if(n > 0)
        printf("%ld\n",n*(n+1)/2);
    else
        printf("%ld\n",(n+1)*(-n+2)/2);
    return 0;
}
