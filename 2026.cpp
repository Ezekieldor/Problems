#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int n, w[110], v[110];

int dp[1110][110];

int f (int item, int disp)
{
	if (item == n || disp == 0) return 0;
	
	int &p = dp[item][disp];
	
	if (p != -1) return p;
	
	if (disp >= w[item])
	{
		p = max (v[item] + f (item + 1, disp - w[item]), f (item + 1, disp));
	}
	else p = f (item + 1, disp);
	
	return p;
}

int main ()
{
	int t, W, K = 1;
	scanf ("%d", &t);
	
	while (t--)
	{
		scanf ("%d%d", &n, &W);
		
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &v[i], &w[i]);
		}
		
		memset (dp, -1, sizeof dp);
		
		int res = f (0, W);

		printf ("Galho %d:\n", K++);
		printf ("Numero total de enfeites: %d\n", res);
		puts ("");
	}
}
