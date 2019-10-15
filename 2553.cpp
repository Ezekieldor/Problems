#include <bits/stdc++.h>
#define MAXN 50

using namespace std;

int n, dp[41][201][201];

struct ii
{
	int g, y;
} v[MAXN];

int f (int item, int g, int y)
{
	if (item == n) return 0;
	
	int &p = dp[item][g][y];
	
	if (p != -1) return p;

	p = f (item + 1, g, y);
	
	if (v[item].g < 0)
	{
		if (g >= fabs (v[item].g))
		{
			p = max (p, 1 + f (item + 1, g - fabs (v[item].g), y + v[item].y));
		}
	}
	else
	{
		if (y >= fabs (v[item].y))
		{
			p = max (p, 1 + f (item + 1, g + v[item].g, y - fabs (v[item].y)));
		}
	}
	
	return p;
}

int main ()
{
	int g, y;
	while (scanf ("%d", &n) != EOF)
	{
		scanf ("%d%d", &g, &y);
		
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &v[i].g, &v[i].y);
		}
		
		memset (dp, -1, sizeof dp);
		
		printf ("%d\n", f (0, g, y));
	}
}
