#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const double EXP=1E-8;
double a[15][15];
double solve(int n)
{
    for(int r=0;r<n;r++)
    {
        for(int i=r;i<n;i++)
        {
            if(i!=r&&fabs(a[i][r])>EXP)
            {
                double tmp=a[i][r]/a[r][r];
                for(int k=0;k<n;k++)
                    a[i][k]=a[i][k]-tmp*a[r][k];
            }
        }
    }
    double ans=1.0;
    for(int i=0;i<n;i++)
        ans*=a[i][i];
    return ans;
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        }
        printf("%.2f\n",solve(n));

    }
    return 0;

}
