#include<iostream>
#include<string>
using namespace std;
string txt[501];
string str[13];
int main()
{
    int len=1;
    cin>>txt[0];
    while(txt[len-1][txt[len-1].size()-1]!='#')
    {
        cin>>txt[len];
        len++;
    }
    while(cin)
    {
        int k=1;
        cin>>str[0];
        while(str[k-1][str[k-1].size()-1]!='#')
        {
            cin>>str[k];
            k++;
        }
        int i,j;
        j=k-2;
        for(i=len-2;i>=0;i--)
        {
            if(j==-1)
                break;
            if(txt[i]==str[j])
            {
                j--;
            }
            else
            {
                j=k-2;
            }
        }
        if(j==-1&&i==len-2||j!=-1)
            cout<<-1<<endl;
        else
            cout<<i+2<<endl;
    }
}
