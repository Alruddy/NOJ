#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000];
int main()
{
    cin>>s;
    int n=strlen(s);
    int index,flag=0;
    for(int i=n-1;i>=0;i--)
    {
        if((s[i]-'0')%2==0)
        {
            index=i;
            flag=1;
            break;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if((s[i]-'0')%2==0&&s[i]<s[n-1])
        {
            index=i;
            break;
        }
    }
    if(flag)
    {
        swap(s[index],s[n-1]);
        cout<<s;
    }
    else
        cout<<-1;

}
