#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
string ans;
string tmp;
int mmax=-1;
map<string,int> mp;
int n;

int main()
{
    while(scanf("%d",&n)==1,n)
    {
        mmax=-1;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            if(!mp.count(tmp)) mp[tmp]=0;
            mp[tmp]++;
            if(mp[tmp]>mmax)
            {
                ans=tmp;
                mmax=mp[tmp];
            }
        }
        cout<<ans<<"\n";
    }



}

