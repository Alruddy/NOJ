#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string Reverse(string s);
int main()
{
    int i=0;
    char ch[25000];
    memset(ch,'\0',25000);
    cin.getline(ch,25000);
    string ss;
    string ssr;

    while(ch[i]!='#')
    {
        ss+=ch[i];
        i++;
    }
    ssr=Reverse(ss);
    int lenss=ss.size();
    while(cin.getline(ch,25000))
    {
        i=0;
        string suss;
        while(ch[i]!='#')
        {
            suss+=ch[i];
            i++;
        }
        string sussr;
        sussr=Reverse(suss);
        int lenssus=suss.size();
        int pos=ssr.find(sussr);
        if(pos!=string::npos)
        {
            int loc=lenss-pos-lenssus;
            int count=0;
            for(int i=0;i<=loc;i++)
            {
                if(ss[i]==' ')
                    count++;
            }
            cout<<count+1<<endl;
        }
        else
            cout<<-1<<endl;
        memset(ch,'\0',25000);
    }
    return 0;

}
string Reverse(string s)
{
    string ss;
    for(int i=s.size()-1;i>=0;i--)
    {
        ss+=s[i];
    }
    return ss;
}


