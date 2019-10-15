#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

int v[1011], n, dp[1011][3010], w[1011];

int f (int item, int disp)
{
	if (disp <= 0) return 0;
	if (item == n) return INF;
	
	int &p = dp[item][disp];
	
	if (p != -1) return p;
	
	p = min (v[item] + f (item + 1, disp - w[item]), f (item + 1, disp));
	
	return p;
}

int main ()
{
	int V;
	while (scanf ("%d%d", &n, &V) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &w[i], &v[i]);
		}
		
		memset (dp, -1, sizeof dp);
		int res = f (0, V);
		if (res > 12345678) printf ("-1\n");
		else printf ("%d\n", res);
	}
}
