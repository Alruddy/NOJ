#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long a,b=0LL,n,k=0;

    while(cin>>n,n)
    {
        b=0LL;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            b+=a;
        }
        cout<<b<<endl<<endl;
    }
    return 0;
}
