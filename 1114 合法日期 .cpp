#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int monthdays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int year,month,day,week;
string s;
map<string,int> mp;
bool ok(int year)
{
    return (year%4==0&&year%100!=0)||(year%400==0);
}
int init()
{
    mp["Sunday"]=0;
    mp["Monday"]=1;
    mp["Tuesday"]=2;
    mp["Wednesday"]=3;
    mp["Thursday"]=4;
    mp["Friday"]=5;
    mp["Saturday"]=6;
}
const int sty=2009,stm=5,stda=29,stw=5;
int alldays=0;

int main()
{
    int n;
    cin>>n;
    init();
    while(n--)
    {
        alldays=0;
        cin>>year>>month>>day>>s;
        if(month>12||month<1)
        {
            printf("NO\n");
            continue;
        }
        if(month!=2&&(day>monthdays[month]||day<1))
        {
            printf("NO\n");
            continue;
        }
        if(month==2)
        {
            if(ok(year)&&day>29||day<1) {printf("NO\n");continue;}
            if(!ok(year)&&day>28||day<1) {printf("NO\n");continue;}
        }
        if(!mp.count(s)){printf("NO\n"); continue;}
        week=mp[s];
        if(year>sty)
        {
            alldays+=216;
            for(int i=2010;i<year;i++)
                if(ok(i)) alldays+=366;
                else    alldays+=365;
            for(int i=1;i<month;i++)
            {
                alldays+=monthdays[i];
                if(i==2&&ok(year))
                    alldays++;
            }
            alldays+=day;
        }
        else if(year<sty)
        {
            alldays+=149;
            for(int i=year+1;i<sty;i++)
                if(ok(i)) alldays+=366;
                else alldays+=365;
            for(int i=month+1;i<=12;i++)
            {
                alldays+=monthdays[i];
                if(i==2&&ok(year))
                    alldays++;
            }
            alldays+=(monthdays[month]-day);
            if(month==2&&ok(year))
                alldays++;
            alldays=-alldays;
        }
        else if(year==sty)
        {
            if(month>stm)
            {
                for(int i=6;i<month;i++)
                {
                    alldays+=monthdays[i];
                }
                alldays+=2;
                alldays+=day;
            }
            else if(month<stm)
            {
                for(int i=month+1;i<5;i++)
                {
                    alldays+=monthdays[i];
                    if(i==2&&ok(year))
                        alldays++;
                }
                alldays+=29;
                alldays+=(monthdays[month]-day);
                if(month==2&&ok(year))
                    alldays++;
                alldays=-alldays;
            }
            else if(month==stm)
            {
                if(day>29)
                    alldays+=day-29;
                else
                {
                    alldays+=29-day;
                    alldays=-alldays;
                }
            }
        }
        alldays=alldays%7;
        alldays=(alldays+14+stw)%7;
        if(alldays==week)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
