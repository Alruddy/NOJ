#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Sort(vector<string> &vs);
int count_1(string str);
int main()
{
    vector<string> vs;
    string str;
    while(cin>>str)
    {
        vs.push_back(str);
    }
    Sort(vs);
    for(int i=0;i<vs.size();i++)
        cout<<vs[i]<<endl;
    return 0;
}
int count_1(string str)
{
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='1')
            count++;
    }
    return count;
}
void Sort(vector<string> &vs)
{
    int i,j,k;
    int len=vs.size();
    for(int i=0;i<len-1;i++)
    {
        k=i;
        for(j=k+1;j<len;j++)
        {
            if((vs[j].length()<vs[k].length())||(vs[j].length()==vs[k].length()&&count_1(vs[j])<count_1(vs[k]))||(vs[j].length()==vs[k].length()&&count_1(vs[j])<count_1(vs[k])&&vs[j]<vs[k]))
                k=j;
        }
        if(k!=i)
        {
            string temp=vs[i];
            vs[i]=vs[k];
            vs[k]=temp;
        }
    }
}







