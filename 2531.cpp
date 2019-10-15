#include <bits/stdc++.h>
#define MAXN 101000
#define INF 123456789
#define ll long long int

using namespace std;

struct ii
{
	int M, m;
	ii () {}
	ii (int M, int m) : M (M), m (m) {}
	ii operator + (ii other)
	{
		return ii (max (M, other.M), min (m, other.m));
	}
};

ii st[MAXN * 4]; 
int v[MAXN];

void update (int no, int l, int r, int pos, ll value)
{
	if (l > pos || r < pos) return;
	if (l == r && r == pos)
	{
		st[no] = ii (value, value);
		return;
	}
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	update (noL, l, mid, pos, value);
	update (noR, mid + 1, r, pos, value);
	st[no] = st[noL] + st[noR];
}

ii query (int no, int l, int r, int i, int j)
{
	if (l > j || r < i) return ii (-INF, INF);
	if (l >= i && r <= j) return st[no];
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	return query (noL, l, mid, i, j) + query (noR, mid + 1, r, i, j);
}

int main ()
{
	int n, m, a, b, val;
	
	while (scanf ("%d", &n) != EOF)
	{	
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &val);
			update (1, 0, n - 1, i, val);
		}
		
		scanf ("%d", &m);
		
		for (int i = 0; i < m; i++)
		{
			scanf ("%d%d%d", &val, &a, &b);
			if (val == 1)
			{
				update (1, 0, n - 1, a - 1, b);
			}
			else
			{
				if (a > b) swap (a, b);
				ii res = query (1, 0, n - 1, a - 1, b - 1);
				printf ("%d\n", (res.M - res.m));
			}
		}
	}
}
