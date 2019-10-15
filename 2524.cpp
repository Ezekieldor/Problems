#include <bits/stdc++.h>
#define INF 1234567899

using namespace std;

int V, n, v[1100], dp[1100][1100];

int f (int item, int val)
{
	if (val == 0)
	{
		return max (0, f (item, V));
	}
	
	if (item == n) return -INF;
	
	int &p = dp[item][val];
	
	if (p != -1) return p;
	
	return p = max (1 + f (item + 1, (val + v[item]) % V), f (item + 1, val));
}

int main ()
{
	while (scanf ("%d%d", &V, &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &v[i]);
		}
		memset (dp, -1, sizeof dp);
		int res = f (0, V);
		if (res < 0) printf ("0\n");
		else printf ("%d\n", res);
	}
}
