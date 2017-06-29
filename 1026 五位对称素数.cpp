#include<iostream>
#include<cmath>
using namespace std;
bool JudgePrime(int x);
bool JudgeSymmetry(int x);
int main()
{
    int n;
    int count=0;
    while(cin>>n)
    {
        if(JudgePrime(n)&&JudgeSymmetry(n))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
bool JudgePrime(int x)
{
    if(x==1)
        return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
bool JudgeSymmetry(int x)
{
    char str[6];
    int i=0;
    while(x)
    {
        int m=x%10;
        str[i++]=m+'0';
        x=x/10;
    }
    str[i]='\0';
    for(int j=0;j<i;j++)
    {
        if(str[j]!=str[i-j-1])
            return false;
    }
    return true;
}
