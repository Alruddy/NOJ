#include<iostream>
#include<cstring>
using namespace std;
char result[2005];
char *add(const char *a,const char *b);
int main()
{
        char a[1002],b[1002];
        cin>>a;
        cin>>b;
        cout<<add(a,b)<<endl;
        return 0;
}
char *add(const char *a,const char *b)
{
    char *presult=result;
    int len_a=strlen(a);
    int len_b=strlen(b);
    int length=(len_a>len_b?len_a:len_b)+1;
    for(int i=len_a,j=len_b,k=1;i>=0||j>=0;i--,j--,k++)
    {
        if(i>=0&&j>=0)
            result[length-k]=a[i]-'0'+b[j]-'0';
        else if(i>=0&&j<0)
            result[length-k]=a[i]-'0';
        else if(i<0&&j>=0)
            result[length-k]=b[j]-'0';
    }
    char front_temp,local_temp;
    for(int i=length-2;i>=1;i--)
    {
        front_temp=char(result[i]/10);
        local_temp=char(result[i]%10);
        if(front_temp>0)
            result[i-1]+=front_temp;
        result[i]=local_temp;
    }
    front_temp=result[0]/10;
    result[0]=result[0]%10;
    int len;
    if(front_temp>0)
    {
        for(int i=length-2;i>=0;i--)
        {
            result[i+1]=result[i];
        }
        result[0]=front_temp;
        result[length]='\0';
        len=length;
    }
    else
    {
        result[length-1]='\0';
        len=length-1;
    }
    for(int i=0;i<len;i++)
        result[i]+='0';
    return presult;
}
