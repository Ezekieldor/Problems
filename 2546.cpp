#include <bits/stdc++.h>
#define MAXN 101000
#define INF 123456789
#define ll long long int

using namespace std;

struct ii
{
	int M, pos;
	ii () {}
	ii (int M, int pos) : M (M), pos (pos) {}
	ii operator + (ii other)
	{
		if (M > other.M) return ii (M, pos);
		if (M == other.M)
		{
			if (pos < other.pos) return ii (M, pos);
			return ii (other.M, other.pos);
		}
		return ii (other.M, other.pos);
	}
};

ii st[MAXN * 4];
int v[MAXN], lz[MAXN * 4];

void lazy (int no, int noL, int noR)
{
	lz[noL] += lz[no];
	lz[noR] += lz[no];
	st[noL].M += lz[no];
	st[noR].M += lz[no];
	lz[no] = 0;
}

void build (int no, int l, int r)
{
	if (l == r)
	{
		st[no] = ii (v[l], l);
		return;
	}
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	build (noL, l, mid);
	build (noR, mid + 1, r);
	st[no] = st[noL] + st[noR];
}

void update (int no, int l, int r, int i, int j, int value)
{
	if (l > j || r < i) return;
	if (l >= i &&  r <= j)
	{
		st[no].M += value;
		if (i == j) st[no].pos = i;
		lz[no] += value;
		return;
	}
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	lazy (no, noL, noR);
	
	update (noL, l, mid, i, j, value);
	update (noR, mid + 1, r, i, j, value);
	st[no] = st[noL] + st[noR];
}

ii query (int no, int l, int r, int i, int j)
{
	if (l > j || r < i) return ii (0, 0);
	if (l >= i && r <= j) return st[no];
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	lazy (no, noL, noR);
	
	return query (noL, l, mid, i, j) + query (noR, mid + 1, r, i, j);
}

int main ()
{
	int n, m, a, b, val;
	char c;
	
	while (scanf ("%d%d", &n, &m) != EOF)
	{	
		for (int i = 0; i <= n * 4; i++)
		{
			lz[i] = 0;
			st[i] = ii (0, 0);
		}
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &v[i]);
		}
		
		build (1, 0, n - 1);
		
		for (int i = 0; i < m; i++)
		{
			scanf (" %c", &c);
			if (c == 'A')
			{
				scanf ("%d%d%d", &a, &b, &val);
				//if (a > b) swap (a, b);
				update (1, 0, n - 1, a - 1, b - 1, val);
			}
			else
			{
				scanf ("%d%d", &a, &b);
				//if (a > b) swap (a, b);
				ii res = query (1, 0, n - 1, a - 1, b - 1);
				printf ("%d\n", res.pos + 1);
			}
		}
	}
}
