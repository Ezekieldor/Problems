#include <bits/stdc++.h>
#define MAXN 100100
#define INF 123456789

using namespace std;

struct point
{
	int x, y;
	point (int x, int y) : x (x), y (y) {}
	point () {}
}
v[MAXN];

double dist (point a, point b)
{
	return hypot (b.x - a.x, b.y - a.y);
}

int n;
double dp[17][1 << 17];

double f (int item, int mask)
{
	if (mask == (1 << n) - 1) return 0.0;
	if (item == n) return INF;
	
	double &p = dp[item][mask];
		
	if (p != -1) return p;
	
	if ((mask & (1 << item)) == (1 << item)) return p = f (item + 1, mask);
	
	p = INF;
	
	mask = (mask | (1 << item));
	
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
		{
			p = min (p, dist (v[item], v[i]) + f (item + 1, mask | (1 << i)));
		}
	}
	
	return p;
}

int main ()
{
	int t, a, b;
	scanf ("%d", &t);

	while (t--)
	{
		scanf ("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &a, &b);
			v[i] = point (a, b);
		}
		
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < (1 << 17); j++)
			{
				dp[i][j] = -1;
			}
		}
		
		printf ("%.2lf\n", f (0, 0));
	}
}
