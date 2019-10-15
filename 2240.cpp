#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

struct ii
{
	int s, c;
	ii () {}
	ii (int s, int c) : s (s), c (c) {}
}
tree1[10010], tree2[10010];

bool vis[10010];

int main ()
{
	//freopen ("in.txt", "r", stdin);
	
	int node, s, c, n, m;
	
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d%d", &node, &s, &c);
		tree1[node] = ii (s, c);
	}
	
	scanf ("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d%d", &node, &c, &s);
		tree2[node] = ii (s, c);
	}
	
	int qC1 = 0, C1 = 1, qC2 = 0, C2 = 1;
	
	int u = 1;
	while (tree1[u].c != 0) u = tree1[u].c, C1++;
	
	u = 1;
	while (tree2[u].c != 0) u = tree2[u].c, C2++;
	
	//cout << C1 << " " << C2 << endl;
	
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int cont = 1;
			int u = i;
			while (tree1[u].c != 0) vis[u] = true, u = tree1[u].c, cont++;
			qC1 = max (qC1, cont);
		}
	}
	
	memset (vis, false, sizeof vis);
	
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i])
		{
			int cont = 1;
			int u = i;
			while (tree2[u].c != 0) vis[u] = true, u = tree2[u].c, cont++;
			qC2 = max (qC2, cont);
		}
	}
	
	//cout << qC1 << " " << qC2 << endl;
	
	printf ("%d\n", min (n + m - min (C1, qC2), n + m - min (C2, qC1)));
}
