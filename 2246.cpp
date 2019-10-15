#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

int ordR[] = {-1, 0, 1, 0};
int ordC[] = {0, 1, 0, -1};
int n, m, v[222][222];

int flood (int r, int c, int val)
{
	if (r < 0 || r == n || c < 0 || c == m) return 0;
	if (v[r][c] != val) return 0;
	v[r][c] = -1;
	
	int p = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int a = ordR[i] + r, b = ordC[i] + c;
		p += flood (a, b, val);
	}
	
	return p + 1;
}

int main ()
{
	//freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf ("%d", &v[i][j]);
		}
	}
	
	int val = INF;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] != -1)
			{
				val = min (val, flood (i, j, v[i][j]));
			}
		}
	}
	
	printf ("%d\n", val);
}
