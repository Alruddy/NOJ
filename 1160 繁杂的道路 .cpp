#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
    }
    cout<<m-n+1<<endl;
    return 0;
}
