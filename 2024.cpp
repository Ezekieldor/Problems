#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

struct ii
{
	int f, s, h;
	ii () {}
	ii (int f, int s, int h) : f (f), s (s), h (h) {}
} v[MAXN][3];

int n, dp[MAXN][3];

int f (int item, int pos)
{
	if (item == n) return 0;
	
	int &p = dp[item][pos];
	
	if (p != -1) return p;
	
	ii a = v[item][0], b = v[item][1], c = v[item][2];
	ii ant = v[item - 1][pos];
	
	p = -1e9;
	
	if ((a.f <= ant.f && a.s <= ant.s) || (a.s <= ant.f && a.f <= ant.s))
	{
		p = max (p, a.h + f (item + 1, 0));
	}
	
	if ((b.f <= ant.f && b.s <= ant.s) || (b.s <= ant.f && b.f <= ant.s))
	{
		p = max (p, b.h + f (item + 1, 1));
	}
	
	if ((c.f <= ant.f && c.s <= ant.s) || (c.s <= ant.f && c.f <= ant.s))
	{
		p = max (p, c.h + f (item + 1, 2));
	}
	
	return p;
}

int main ()
{
	int a, b, c;
	while (scanf ("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d%d%d", &a, &b, &c);
			v[i][0] = ii (a, b, c);
			v[i][1] = ii (a, c, b);
			v[i][2] = ii (b, c, a);
		}
		
		int res = 0;
		
		memset (dp, -1, sizeof dp);
		
		if (n == 1)
		{
			printf ("%d\n", max (v[0][0].h, max (v[0][1].h, v[0][2].h)));
			continue;
		}
		
		for (int i = 0; i < 3; i++)
		{
			int aux = f (1, i);
			if (aux > 0) res = max (res, aux + v[0][i].h);
		}
		
		printf ("%d\n", (res == 0 ? -1 : res));
	}
}
