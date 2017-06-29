#include<iostream>
using namespace std;
int main()
{
    int n;
    int array[100];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>array[i];
        int max,min;
        max=min=array[0];
        for(int i=0;i<n;i++)
        {
            if(max<array[i])
                max=array[i];
            if(min>array[i])
                min=array[i];
        }
        cout<<max<<" "<<min<<endl;
    }
    return 0;
}
