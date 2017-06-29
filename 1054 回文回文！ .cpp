#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char buf[2000];
int main()
{
    while(gets(buf))
    {
        int n=strlen(buf);
        int flag=0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {

            if(tolower(buf[i])!=tolower(buf[j]))
            {
                flag=1;
                break;
            }
        }
        if(flag)
            puts("Not Palindrome.");
        else
            puts("Bingle! Palindrome.");

    }



}
