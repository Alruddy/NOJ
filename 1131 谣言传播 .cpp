#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int father[21000];

int find(int x)
{
	return x == father[x] ? x : father[x] = find(father[x]);
}



int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, t;
		scanf("%d%d%d", &n, &t, &m);
		for(int i = 0; i <= n; i++)
			father[i] = i;
		for(int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int x = find(a);
			int y = find(b);
			if(x != y)
			{
				father[x] = y;
			}
		}

		bool flag = true;
		int root = find(t);
		for(int i = 0; i < n; i++)
		{
			if(find(i) != root)
			{
				flag = false;
			}

		}

		if(flag)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}


	return 0;
}
