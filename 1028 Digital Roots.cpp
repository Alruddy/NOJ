#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(true)
    {
        cin>>str;
        if(str=="0")
            break;;
        int num=0;
        for(int i=0;i<str.length();i++)
        {
            num+=str[i]-'0';
            if(num>9)
                num=num%10+num/10;
        }
        cout<<num<<endl;
    }
    return 0;
}
