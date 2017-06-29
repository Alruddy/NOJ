#include<iostream>
#include<cmath>
using namespace std;
void JudgeTriangle(double a,double b,double c);
int main()
{
    double a,b,c;
    while(true)
    {
        cin>>a>>b>>c;
        if(fabs(a-b)<1e-4&&fabs(a-c)<1e-4&&fabs(a-0)<1e-4)
            break;
        JudgeTriangle(a,b,c);
    }
    cout<<"End"<<endl;
    return 0;
}
void JudgeTriangle(double a,double b,double c)
{
    if(a+b>c&&a+c>b&&b+c>a)
    {
        if((fabs(a*a-b*b-c*c)<1e-3||fabs(a*a+b*b-c*c)<1e-3||fabs(c*c+a*a-b*b)<1e-3)
           &&(fabs(a-b)<1e-4&&fabs(c-b)>1e-4||fabs(a-c)<1e-4&&fabs(a-b)>1e-4||fabs(c-b)<1e-4&&fabs(a-b)<1e-4))
        {
            cout<<"Isosceles right triangle"<<endl;
            return ;
        }
        if(fabs(a-b)<1e-4&&fabs(c-b)<1e-4&&fabs(a-c)<1e-4)
        {
            cout<<"Equilateral triangle"<<endl;
            return;
        }
        if(fabs(a*a-b*b-c*c)<1e-3||fabs(a*a+b*b-c*c)<1e-3||fabs(c*c+a*a-b*b)<1e-3)
        {
            cout<<"Right triangle"<<endl;
            return ;
        }
        if(fabs(a-b)<1e-4&&fabs(c-b)>1e-4||fabs(a-c)<1e-4&&fabs(a-b)>1e-4||fabs(c-b)<1e-4&&fabs(a-b)>1e-4)
        {
            cout<<"Isosceles triangle"<<endl;
            return ;
        }
        cout<<"General triangle"<<endl;
    }
    else
    {
        cout<<"Not a triangle"<<endl;
    }
}
