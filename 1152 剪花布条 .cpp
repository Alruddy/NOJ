#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

char str[1005],b[1005];
int main()
{
    while(scanf("%s", str), str[0] != '#')
    {
        scanf("%s", b);

        int cnt = 0;
        int p = 0;
        int len = strlen(b);
        while(true)
        {
            char *x = strstr(str + p, b);
            if(x == NULL)
                break;
            p = x - str + len;
            cnt++;
        }
        cout<<cnt<<endl;
    }



    return 0;
}
