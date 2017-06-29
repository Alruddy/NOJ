#include<iostream>
using namespace std;
int main()
{
    int n;
    int *height;
    cin>>n;
    height=new int[n];
    for(int i=0;i<n;i++)
        cin>>height[i];
    int count=0;
    for(int j=0;j<n;j++)
    {
        int temp_count=1;
        int max=height[j];
        for(int i=j;i<n;i++)
        {
            if(max>height[i])
            {
                max=height[i];
                temp_count++;
            }
        }
        count=count>temp_count?count:temp_count;
    }
    cout<<count<<endl;
    return 0;
}
