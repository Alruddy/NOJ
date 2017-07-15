#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <map>
using namespace std;

int n, m;
int name[20100];
int main()
{
	while(scanf("%d", &n), n != 0)
	{
		int k = 1;
		map<string,int> mp;
		memset(name, 0 ,sizeof(name));
		mp.clear();
		scanf("%d", &m);
		for(int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			for(int j = 0; j < tmp.size(); j++)
				tmp[j] = toupper(tmp[j]);
			if(!mp.count(tmp))
			{
				mp[tmp] = k;
				name[k++] = 1;
			}
		}
		for(int i = 0; i < m; i++)
		{
			string tmp;
			cin >> tmp;
			for(int j = 0; j < tmp.size(); j++)
				tmp[j] = toupper(tmp[j]);
			if(mp.count(tmp) && name[mp[tmp]] == 1)
			{
				name[mp[tmp]] = 0;
			}
		}

		int cnt = 0;
		for(int i = 1; i < k; i++)
		{
			if(name[i])
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}