#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool JudgeAceNum(int x);
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<n<<":";
        for(int i=2,j=2;i<=n;i=j*(j+1)/2)
        {
            if(JudgeAceNum(i))
                cout<<" "<<i;
                j++;
        }
        cout<<endl;
    }
    return 0;
}
bool JudgeAceNum(int x)
{
    vector<int> vi;
    for(int i=1;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            vi.push_back(i);
            if(i!=x/i)
                vi.push_back(x/i);
        }
    }
    int sum=0;
    for(int i=0;i<vi.size();i++)
        sum+=vi[i];
    return sum==2*x;
}
