#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    printf("Gnomes:\n");
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((a<=b&&b<=c)||(a>=b&&b>=c))
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
}
