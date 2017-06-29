#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
double a,b;
int n;
double c[20];

double calculate(double x,double y,int n)
{
    double res=0;
    for(int i=n;i>=0;i--)
        res=res+c[i]*(pow(x,i+1)-pow(y,i+1))/(i+1);
    return res;
}

int main()
{
    cin>>n>>a>>b;

    for(int i=0;i<=n;i++)
    {
        cin>>c[i];
        c[i]=c[i]*1000;
    }

    double ans;
    ans=calculate(b,a,n);
    printf("%d",int((ans+500)/1000));
    return 0;
}
