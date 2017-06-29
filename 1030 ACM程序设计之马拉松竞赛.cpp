#include<iostream>
using namespace std;
int main()
{
    int n;
    int goals[1001];
    int standard;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>goals[i];
    }
    cin>>standard;

    int pos;
    for(int i=0;i<n;i++)
    {
        if(goals[i]>=standard)
        {
            pos=i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(goals[i]<standard&&i>pos)
        {
            int temp=goals[i];
            for(int j=i-1;j>=pos;j--)
                goals[j+1]=goals[j];
            goals[pos]=temp;
            pos++;
            i--;
        }
    }
    for(int i=0;i<n-1;i++)
        cout<<goals[i]<<" ";
    cout<<goals[n-1]<<endl;

    for(int i=0;i<n;i++)
        for(int j=n-1;j>i;j--)
        {
            if(goals[j]<goals[j-1])
            {
                int temp=goals[j];
                goals[j]=goals[j-1];
                goals[j-1]=temp;
            }
        }

    for(int i=0;i<n-1;i++)
    {
        if(goals[i]>=standard)
            cout<<goals[i]<<" ";
    }
    cout<<goals[n-1]<<endl;
    return 0;
}
