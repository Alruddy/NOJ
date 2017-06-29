#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[400];
char s2[500];
char s8[400];
int main()
{
    cin>>s;
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        int tmp;
        if(s[i]<='9'&&s[i]>='0')
            tmp=s[i]-'0';
        else
            tmp=s[i]-'A'+10;
        for(int j=i*4+3;j>=i*4;j--)
        {
            s2[j]=tmp%2;
            tmp>>=1;
        }
    }

    n=n*4;
    int k=n%3;
    int tmp=0;
    for(int i=0;i<k;i++)
    {
        tmp=tmp*2+s2[i];
    }
    if(tmp)
        printf("%d",tmp);
    for(int i=k;i<n;i+=3)
    {
        tmp=0;
        for(int j=i;j<i+3;j++)
            tmp=tmp*2+s2[j];
        printf("%d",tmp);
    }



    return 0;
}
