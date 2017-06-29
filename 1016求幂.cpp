#include<iostream>
#include"string"
#include"vector"
using namespace std;
struct longfloat
{
    longfloat()
    {
        num=vector<short>(0);
        point=0;
    }
    longfloat(int n)
    {
        num=vector<short>(n,0);
        point=0;
    }
    vector<short> num;
    int point;
};
istream& operator>>(istream&sin,longfloat&r)
{
    string s;
    sin>>s;
    if(s.find(".",0)==string::npos)
    {
        s=s+".";
    }
    r.point=s.size()-1-s.find(".",0);
    r.num=vector<short>(0);
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]!='.')
            r.num.push_back(s[i]-'0');
    }
    return sin;
}
ostream& operator<<(ostream&sout,longfloat r)
{
    while(r.num[r.num.size()-1]==0&&r.num.size()>r.point)
        r.num.pop_back();
    int n=0;
    while(r.num[n]==0&&n<r.point)
        n++;
    for(int i=r.num.size()-1,j=0; i>=n; i--,j++)
    {
        if(j==r.num.size()-r.point)
            sout<<".";
        sout<<r.num[i];
    }
    return sout;
}
longfloat operator*(const longfloat&r1,const longfloat&r2)
{
    longfloat tem(r1.num.size()+r2.num.size()-1);
    tem.point=r1.point+r2.point;
    for(int i=0; i<r1.num.size(); i++)
    {
        for(int j=0; j<r2.num.size(); j++)
        {
            tem.num[i+j]+=r1.num[i]*r2.num[j];
        }
    }
    for(int i=0; i<tem.num.size()-1; i++)
    {
        if(tem.num[i]>=10)
        {
            tem.num[i+1]+=tem.num[i]/10;
            tem.num[i]%=10;
        }
    }
    while(tem.num[tem.num.size()-1]>=10)
    {
        tem.num.push_back(tem.num[tem.num.size()-1]/10);
        tem.num[tem.num.size()-2]%=10;
    }

    return tem;
}
longfloat pow(longfloat r,int n)
{
    longfloat tem=r;
    for(int i=1; i<n; i++)
    {
        r=r*tem;
    }
    return r;
}
int main()
{
    longfloat r;
    int n;
    while(cin>>r>>n)
        cout<<pow(r,n)<<endl;
    return 0;
}













