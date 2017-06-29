#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char s[5000];
int main()
{
    int n;
    //freopen("D://input.txt","wr",stdin);
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(s);
        puts(s);
        printf("\n");
    }
    int k=0;
    while(gets(s))
    {
        if(k++)
            printf("\n");
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==' '&&s[i+1]!=' '&&s[i+1]!='\0')
                printf("\n\n");
            else if(s[i]!='\n')
                printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
