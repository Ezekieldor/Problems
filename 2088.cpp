#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

typedef pair <int, double> ii;
typedef vector <ii> vii;

struct point
{
	int x, y;
	point () {}
	point (int x, int y) : x (x), y (y) {}
}
v[20];

double dist (point a, point b)
{
	return hypot (b.x - a.x, b.y - a.y);
}

double dp[20][1 << 16];
int n;

double f (int item, int mask, vii AdjList[])
{
	if (mask == (1 << n) - 1 && item == 0) return 0.0;
	
	double &p = dp[item][mask];
	
	if (p != -1) return p;
	
	p = INF;
	
	for (int i = 0; i < (int)AdjList[item].size (); i++)
	{
		ii v = AdjList[item][i];
		p = min (p, v.second + f (v.first, mask | (1 << v.first), AdjList));
	}
	return p;
}

int main ()
{
	int x, y;
	
	while (scanf ("%d", &n), n)
	{	
		n++;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d", &x, &y);
			v[i] = point (x, y);
		}
		
		vii AdjList[n + 15];
		
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double d = dist (v[i], v[j]);
				AdjList[i].push_back (ii (j, d));
				AdjList[j].push_back (ii (i, d));
			}
		}
		
		for (int i = 0; i < 20; i++)
			for (int j = 0;j < (1 << 16); j++)
				dp[i][j] = -1;
				
		printf ("%.2lf\n", f (0, 1 << 0, AdjList));
	}
}
