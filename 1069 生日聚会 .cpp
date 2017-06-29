#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        v.clear();
        cin>>n;
        for(int k=1;k<=n;k++)
        {
            int s=0;
            for(int i=2;i<=n;i++)
                s=(s+k)%i;
            if(s==0)
                v.push_back(k);
        }
        cout<<v.size()<<endl;
        if(v.size()==0)
            continue;
        for(int i=0;i<v.size();i++)
        {
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        if(t)
            printf("\n");
    }
    return 0;
}
