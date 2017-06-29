#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int u;
    int v;
    vector<string> animal;
}edge[250005];
bool cmpo(Edge a,Edge b)
{
    if(a.u==b.u)
        return a.v<b.v;
    return a.u<b.u;
}
int main()
{
    string info;
    int u,v,k=0;
    string an;

    while(getline(cin,info))
    {
        stringstream ss(info);
        ss>>u>>v;
        if(u>v)
            swap(u,v);
        edge[k].u=u;edge[k].v=v;
        while(ss>>an)
        {
            edge[k].animal.push_back(an);
        }
        sort(edge[k].animal.begin(),edge[k].animal.end());

        k++;

    }
    sort(edge,edge+k,cmpo);

    for(int i=0;i<k;i++)
    {
        cout<<edge[i].u<<" "<<edge[i].v<<" ";
        for(int j=0;j<edge[i].animal.size();j++)
        {
            if(j) cout<<" ";
            cout<<edge[i].animal[j];
        }
        cout<<endl;
    }
    return 0;
}
