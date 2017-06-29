#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
LL f[50]={1,2,3};
int main()
{
    for(int i=2;i<=46;i++)
        f[i]=f[i-1]+f[i-2];
    int q;
    cin>>q;
    while(q--)
    {
        int tmp;
        cin>>tmp;
        cout<<f[tmp]<<endl;
    }






    return 0;
}
