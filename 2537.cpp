#include <bits/stdc++.h>
#define MAXN 1110

using namespace std;

int ft[MAXN][MAXN];

int last (int x)
{
	return x & (-x);
}

void update (int x, int y, int value)
{
	for (int i = x; i < MAXN; i += last (i))
	{
		for (int j = y; j < MAXN; j += last (j))
		{
			ft[i][j] += value;
		}
	}
}

int query (int x, int y)
{
	int value = 0;
	for (int i = x; i > 0; i -= last (i))
	{
		for (int j = y; j > 0; j -= last (j))
		{
			value += ft[i][j];
		}
	}
	
	return value;
}

int main ()
{
	int n, m, a, a1, b1, a2, b2;
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		memset (ft, 0, sizeof ft);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf ("%d", &a);
				update (i, j, a);
			}
		}
		//cout << query (2, 4) << endl;
		for (int i = 0; i < m; i++)
		{
			scanf ("%d%d", &a1, &b1);
			update (a1, b1, 1);
			scanf ("%d%d%d%d", &a1, &b1, &a2, &b2);
			int v1 = query (a1 - 1, b1 - 1);
			int v2 = query (a1 - 1, b2);
			int v3 = query (a2, b1 - 1) - v1;
			//cout << v1 << " " << v2 << " " << v3 << endl;
			printf ("%d\n", query (a2, b2) - (v2 + v3));
		}
	}
}
