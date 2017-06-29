#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string str;
    while(true)
    {
        getline(cin,str);
        double sum=0;
        if(str[0]=='#')
            break;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
                sum+=(i+1)*(str[i]-'A'+1);
            if(str[i]==' ')
                sum+=0;
        }
        cout<<sum<<endl;
    }
    return 0;
}
