#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[100050];
void quick_sort(int *a,int l,int r)
{
    if(l<r)
    {
        int i=l,j=r+1;
        do
        {
            do
            {
                i++;
            }while(a[i]<a[l]);
            do
            {
                j--;
            }while(a[j]>a[l]);
            if(i<j)
                swap(a[i],a[j]);
        }while(i<j);
        swap(a[l],a[j]);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,r);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<a[i];
    }
}
