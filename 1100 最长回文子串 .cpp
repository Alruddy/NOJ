#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
char s[5050];
char str[5050];
int pos[5050];

int main()
{
    int ch,k=0;
    /*while((ch=getchar())!='\n')
    {
        s[i]=char(ch);
        if(isalpha(ch))
        {
            str[k]=char(tolower(ch));
            pos[k]=i;
            k++;
        }
        i++;
    }*/
    fgets(s, 5000, stdin);
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            str[k]=tolower(s[i]);
            pos[k]=i;
            k++;
        }
    }
    str[k]='\0';
    //printf("%s\n%s\n",str,s);
    int ss=0,ee=-1,maxlength=0;

    for(int i=0;i<k;i++)
    {
        int l,r,ln;
        l=r=i;
        while(l>=0&&r<k&&l<=r&&str[l]==str[r])
        {
            l--;r++;
        }
        l++;r--;
        ln=r-l+1;
        if(ln>maxlength)
        {
            maxlength=ln;
            ss=l;
            ee=r;
        }
        l=i,r=i+1;
        if(l>=0&&r<k&&str[l]==str[r])
        {
            while(l>=0&&r<k&&l<r&&str[l]==str[r])
            {
                l--;r++;
            }
            l++;r--;
            ln=r-l+1;
            if(ln>maxlength)
            {
                maxlength=ln;
                ss=l;
                ee=r;
            }
        }

    }
    for(int i=pos[ss];i<=pos[ee];i++)
        putchar(s[i]);
    putchar('\n');

    return 0;
}
