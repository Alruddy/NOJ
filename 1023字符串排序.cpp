#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int CountA(string str);
bool cmp(string a,string b);
int main()
{
    vector<string> vs(0);
    string str;
    while(cin>>str)
    {
        vs.push_back(str);
    }
    sort(vs.begin(),vs.end(),cmp);
    for(int i=0;i<vs.size();i++)
        cout<<vs[i]<<endl;
    return 0;
}
int CountA(string str)
{
    char *p=&str[0];
    int count=0;
    while(*p)
    {
        if(*p=='A')
            count++;
        p++;
    }
    return count;
}
bool cmp(string a,string b)
{
    return CountA(a)<CountA(b);
}
