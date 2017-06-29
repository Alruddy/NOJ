#include<iostream>
using namespace std;
int result[1000];
int Mul2(int *re,int n);
int main()
{
        int n;
        int length=1;
        cin>>n;
        result[0]=1;
        for(int i=0;i<n;i++)
        {
            length=Mul2(result,length);
        }
        for(int i=0;i<length;i++)
            cout<<result[i];
        cout<<endl;
    return 0;
}
int Mul2(int *re,int n)
{
    int front_temp,local_temp;
    for(int i=n-1;i>=0;i--)
    {
        re[i]*=2;
    }
    for(int i=n-1;i>=1;i--)
    {
        front_temp=re[i]/10;
        local_temp=re[i]%10;
        if(front_temp>0)
            re[i-1]+=front_temp;
        re[i]=local_temp;
    }
    front_temp=re[0]/10;
    re[0]=re[0]%10;
    if(front_temp>0)
    {
        for(int i=n-1;i>=0;i--)
        {
            re[i+1]=re[i];
        }
        re[0]=front_temp;
        n++;
    }
    return n;
}
