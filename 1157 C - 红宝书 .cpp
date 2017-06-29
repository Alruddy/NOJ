#include <iostream>
#include <set>
using namespace std;
set<string> dir;
int m,n;
int main()
{
    cin>>m>>n;
    string word;
    dir.clear();
    while(m--)
    {
        cin>>word;
        dir.insert(word);
    }
    int cnt=0;
    while(n--)
    {
        cin>>word;
        if(!dir.count(word))
            cnt++;
    }
    cout<<cnt;
    return 0;

}
