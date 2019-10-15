#include <bits/stdc++.h>
#define INF 1234567899

using namespace std;

int dp[1010][60], w[1010], v[1010], n;


int f (int item, int disp)
{	
	if (disp == 0 || item == n) return 0;
	int &p = dp[item][disp];
	
	if (p != -1) return p;

	if (disp >= w[item])
		p = max (f (item + 1, disp), v[item] + f (item + 1, disp - w[item]));
	else p = f (item + 1, disp);
	
	return p;
}

int main ()
{
	int W, K = 1;
	while (scanf ("%d%d", &n, &W), n || W)
	{	
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &w[i], &v[i]);
		}
	
		memset (dp, -1, sizeof dp);
		int res = f (0, W);
		printf ("Caso %d: %d\n", K++, res);
	}
}
