#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
void Rtranscon(stack<char> &s,int num,int r);
int main()
{
    int n;
    int r,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num>>r;
        stack<char> s;
        Rtranscon(s,num,r);
        if(num<0)
            cout<<"-";
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
void Rtranscon(stack<char> &s,int num,int r)
{
    int m,n=fabs(num);
    do
    {
        m=n/r;
        n=n%r;
        if(n>=0&&n<=9)
            s.push(n+'0');
        else
        {
            switch(n)
            {
            case 10:
                s.push('A');
                break;
            case 11:
                s.push('B');
                break;
            case 12:
                s.push('C');
                break;
            case 13:
                s.push('D');
                break;
            case 14:
                s.push('E');
                break;
            case 15:
                s.push('F');
                break;
            }
        }
        n=m;
    }while(n);
}
