#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            cout<<1<<endl;
        else if(n==1)
            cout<<0<<endl;
        else
        {
            if(n%2)
            {
                cout<<4;
                n--;
            }
            while(n)
            {
                cout<<8;
                n-=2;
            }
            cout<<endl;
        }
    }
}
