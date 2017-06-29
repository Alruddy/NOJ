#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    LL n,cnt=0,tmp=0;
    while(scanf("%I64d",&n)!=EOF)
    {
        cnt=tmp=0;
        do
        {
            tmp=(tmp*10+1)%n;
            cnt++;
        }while(tmp);
        printf("%I64d\n",cnt);
    }
    return 0;
}
