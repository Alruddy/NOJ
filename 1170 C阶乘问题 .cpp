#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int g[20]={1,6,2,6,4,4,4,8,4,6,6};
const int m[4]={2,6,8,4};
const int mod = 1e7;

int getfive(int x)
{
    if(x == 0) return 0;
    return (getfive(x/5)+x/5) % 4;
}

int getf(int x)
{
    if(x < 10) return g[x];
    return (getf(x/5) * g[x % 10 == 0 ? 10 : x % 10])%10;
}

int main()
{
    int n;
    //freopen("C:\\Users\\Alruddy\\Desktop\\www.txt","r",stdin);

    while(EOF != scanf("%d", &n))
    {
        if(n == 0 || n == 1)
        {
            printf("%d\n", 1);
            continue;
        }
        int ans = getf(n);
        int po = getfive(n);
        //cout<<ans<< " "<<po<<endl;
        for(int i = 0; i < 4; i++)
        {
            if(ans == m[i])
            {
                ans = m[(po + i) % 4];
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
