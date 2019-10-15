#include <bits/stdc++.h>

using namespace std;

int v[111], n, dp[111][10010], w[111];

int f (int item, int disp)
{
	if (item == n || disp == 0) return 0;
	
	int &p = dp[item][disp];
	
	if (p != -1) return p;
	
	if (disp >= w[item])
		p = max (v[item] + f (item + 1, disp - w[item]), f (item + 1, disp));
	else p = f (item + 1, disp);
	
	return p;
}

int main ()
{
	int V;
	while (scanf ("%d%d", &n, &V) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &v[i]);
		}
		
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &w[i]);
		}
		memset (dp, -1, sizeof dp);
		printf ("%d\n", f (0, V));
	}
}
