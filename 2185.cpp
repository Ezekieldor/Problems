#include <bits/stdc++.h>

using namespace std;

int st[4 * 100100], lz[4 * 100100];

void prop (int no, int noL, int noR, int l, int r, int mid)
{
	if (lz[no] != -1)
	{
		lz[noL] = lz[no];
		lz[noR] = lz[no];
		
		if ((mid - l + 1) % 2 == 0) st[noL] = 0;
		else st[noL] = lz[no];
		
		if ((r - (mid + 1) + 1) % 2 == 0) st[noR] = 0;
		else st[noR] = lz[no];
	}
	
	lz[no] = -1;
}

void update (int no, int l, int r, int i, int j, int val)
{
	if (l > j || r < i) return;
	if (l >= i && r <= j)
	{
		if ((r - l + 1) % 2 == 0) st[no] = 0;
		else st[no] = val;
		
		lz[no] = val;
		return; 
	}
	
	int mid = (l + r) / 2;
	int noL = no * 2, noR = no * 2 + 1;
	
	prop (no, noL, noR, l, r, mid);
	
	update (noL, l, mid, i, j, val);
	update (noR, mid + 1, r, i, j, val);
	st[no] = (st[noL] ^ st[noR]);
}

int query (int no, int l, int r, int i, int j)
{
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return st[no];
	
	int mid = (l + r) / 2;
	int noL = no * 2, noR = no * 2 + 1;
	
	prop (no, noL, noR, l, r, mid);
	
	return (query (noL, l, mid, i, j) ^ query (noR, mid + 1, r, i, j));
}

int main ()
{
	int n, m, val, a, b, c;
	scanf ("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &val);
		update (1, 0, n - 1, i, i, val);
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d%d", &a, &b, &c);
		
		update (1, 0, n - 1, a - 1, b - 1, c);
		
		if (query (1, 0, n - 1, 0, n - 1) != 0) printf ("Possivel\n");
		else printf ("Impossivel\n");
	}
}
