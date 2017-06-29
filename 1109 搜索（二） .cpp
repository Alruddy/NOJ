#include <cstdio>
#include <iostream>
using namespace std;
int t,n,m,i;
int a[1000010];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        int l=0,r=n-1,flag=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[mid]>m)
                r=mid-1;
            else if(a[mid]<m)
                l=mid+1;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");




    }



}
