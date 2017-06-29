#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
deque<LL> q;
int n,m;
char cmd[10];
int tmp;
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>cmd;
        if(strcmp(cmd,"push")==0)
        {
            if(q.size()==n)
                q.pop_front();
            cin>>tmp;
            q.push_back(tmp);
        }
        else
        {
            if(q.empty())
            {
                cout<<"Empty!\n";
            }
            else
            {
                tmp=q.back();
                q.pop_back();
                cout<<tmp<<"\n";
            }

        }
    }
    return 0;
}
