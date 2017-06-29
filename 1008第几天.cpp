#include<iostream>
using namespace std;
const int NormalMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int SpecialMonth[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year,month,day;
    while(true)
    {
        int total=0;
        int current_day;
        cin>>year;
        if(year==-1)
            break;
        cin>>month>>day;
        if(year%4==0&&year%100!=0||year%400==0)
        {
            for(int i=0;i<month;i++)
                total+=SpecialMonth[i];
            total+=day;
        }
        else
        {
            for(int i=0;i<month;i++)
                total+=NormalMonth[i];
            total+=day;
        }
        current_day=total;
        for(int i=2000;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||i%400==0)
                total+=366;
            else
                total+=365;
        }
        total--;
        cout<<total<<endl;
        cout<<current_day<<endl;
    }
    return 0;
}
