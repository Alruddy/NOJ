#include <stdio.h>
#include <iostream>
using namespace std;

int l[500005],r[500005];
int m,n;
char cmd[5];
void init()
{
    r[0]=1;
    l[0]=0;
    for(int i=1;i<500004;i++)
    {
        l[i]=i-1;
        r[i]=i+1;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    init();
    for(int i=0;i<m;i++)
    {
        scanf("%s %d %d",cmd,&a,&b);
        if(cmd[0]=='B')
        {
            r[l[a]]=r[a];
            l[r[a]]=l[a];

            r[a]=r[b];
            l[a]=b;

            l[r[a]]=a;

            r[b]=a;
        }
        else
        {
            r[l[a]]=r[a];
            l[r[a]]=l[a];

            r[a]=b;
            l[a]=l[b];

            l[b]=a;

            r[l[a]]=a;
        }
    }
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(i) printf(" ");
        p=r[p];
        printf("%d",p);
    }
    printf("\n");


    return 0;
}
