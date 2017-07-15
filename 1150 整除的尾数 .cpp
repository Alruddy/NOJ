#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b), a || b)
    {
        int tmp = a % b;
        tmp *= 100;
        int flag = 0;
        for(int i = 0; i < 100; i++)
        {
            if((tmp + i) % b == 0)
            {
                if(flag) printf(" ");
                flag = 1;
                printf("%02d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
