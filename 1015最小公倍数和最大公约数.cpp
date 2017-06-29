#include<iostream>
using namespace std;
int Gcd(int m,int n);
int main()
{
    int m,n;
    cin>>m>>n;
    int gcd=Gcd(m,n);
    int lcm=m*n/gcd;
    cout<<gcd<<" "<<lcm<<endl;
    return 0;
}
int Gcd(int m,int n)
{
    int r;
    do
    {
        r=m%n;
        m=n;
        n=r;
    }while(n);
    return m;
}
