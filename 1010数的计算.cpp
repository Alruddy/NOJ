#include<iostream>
using namespace std;
int total[2000];
int main()
{
    int n;
    cin>>n;
    fill(total,total+2000,1);
    for(int i=2;i<=n;i=i+2)
    {
        total[i]=total[i-1]+total[i/2];
        total[i+1]=total[i];
    };
    cout<<total[n];
    return 0;
}
