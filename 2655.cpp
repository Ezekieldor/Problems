#include <bits/stdc++.h>
#define MAXN 101000
#define INF 123456789
#define ll long long int

using namespace std;

ll st[MAXN * 4], v[MAXN];

void update (int no, int l, int r, int pos, ll value)
{
	if (l > pos || r < pos) return;
	if (l == r && r == pos)
	{
		st[no] = value;
		return;
	}
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	update (noL, l, mid, pos, value);
	update (noR, mid + 1, r, pos, value);
	st[no] = (st[noL] | st[noR]);
}

ll query (int no, int l, int r, int i, int j)
{
	if (l > j || r < i) return 0LL;
	if (l >= i && r <= j) return st[no];
	
	int mid = ((l + r) >> 1);
	int noL = (no << 1), noR = noL + 1;
	
	return (query (noL, l, mid, i, j) | query (noR, mid + 1, r, i, j));
}

int main ()
{
	ll n, m, a, b, val, q;
	
	scanf ("%lld%lld%lld", &n, &q, &m);
		
	for (int i = 0; i < n; i++)
	{
		scanf ("%lld", &val);
		update (1, 0, n - 1, i, (1LL << val));
	}

	for (int i = 0; i < q; i++)
	{
		scanf ("%lld%lld%lld", &val, &a, &b);
		if (val == 2)
		{
			update (1, 0, n - 1, a - 1, (1LL << b));
		}
		else
		{
			if (a > b) swap (a, b);
			ll res = query (1, 0, n - 1, a - 1, b - 1);
			printf ("%d\n", __builtin_popcountll (res));
		}
	}
}
