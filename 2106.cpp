#include <bits/stdc++.h>
#define MAXN 101000
#define ll long long int

using namespace std;

typedef pair <int, int> ii;

int n, dp[18][1 << 18], v[20][20];

int f (int pos, int mask)
{
	if (mask == (1 << n) - 1) return 0;
	int &p = dp[pos][mask];
	
	if (p != -1) return p;
	
	p = 1e9;
	
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) != (1 << i))
		{
			p = min (p, v[i][pos] + f (pos + 1, mask | (1 << i)));
		}
	}
	
	return p;
}

int main ()
{
	while (scanf ("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf ("%d", &v[i][j]);
			}
		}
		
		memset (dp, -1, sizeof dp);
		
		printf ("%d\n", f (0, 0));
	}
}
