#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int p1vsp2(char p1,char p2)
{
    if(p1==p2)
        return 0;
    if((p1=='R'&&p2=='S')||(p1=='S'&&p2=='P')||(p1=='P'&&p2=='R'))
        return 1;
    return -1;
}

char P1[100],P2[100];
int main()
{
    while(EOF!=scanf("%s%s",P1,P2)&&P1[0]!='E')
    {
        int n=strlen(P1);
        int p1,p2;
        p1=p2=0;
        for(int i=0;i<n;i++)
        {
            int res=p1vsp2(P1[i],P2[i]);
            if(res==1) p1++;
            else if(res==-1) p2++;
        }
        printf("P1: %d\nP2: %d\n",p1,p2);
    }
    return 0;
}
