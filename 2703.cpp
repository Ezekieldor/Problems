#include <bits/stdc++.h>
#define MAXN 200100

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int n, m;
int pos[MAXN], head[MAXN];
int heavy[MAXN];
int st[4 * MAXN], lz[4 * MAXN];
int parentSet[MAXN];
vii AdjList[MAXN];
int parent[MAXN], h[MAXN];
int mx[MAXN];

int findSet (int a)
{
	if (parentSet[a] == a) return a;
	return parentSet[a] = findSet (parentSet[a]);
}

void unionSet (int a, int b)
{
	a = findSet (a);
	b = findSet (b);
	parentSet[b] = a;
}

void prop (int no, int noL, int noR, int l, int r, int mid)
{
	lz[noL] += lz[no];
	lz[noR] += lz[no];
	st[noL] += lz[no] * (mid - l + 1);
	st[noR] += lz[no] * (r - (mid + 1) + 1);
	lz[no] = 0;
}

void update (int no, int l, int r, int i, int j, int val)
{
	if (l > j || r < i) return;
	if (l >= i && r <= j)
	{
		st[no] = val * (r - l + 1);
		lz[no] = val;
		return;
	}
	
	int mid = (l + r) / 2;
	int noL = no * 2, noR = no * 2 + 1;
	prop (no, noL, noR, l, r, mid);
	
	update (noL, l, mid, i, j, val);
	update (noR, mid + 1, r, i, j, val);
	st[no] = max (st[noL], st[noR]);
}

int query (int no, int l, int r, int i, int j)
{
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return st[no];
	
	int mid = (l + r) / 2;
	int noL = no * 2, noR = no * 2 + 1;
	
	prop (no, noL, noR, l, r, mid);
	
	return max (query (noL, l, mid, i, j), query (noR, mid + 1, r, i, j));
}

int dfs (int u, int ant)
{
	int qtd = 1, bigger = 0;
	
	for (int i = 0; i < (int)AdjList[u].size (); i++)
	{
		ii v = AdjList[u][i];
		
		if (v.first != ant)
		{
			h[v.first] = h[u] + 1;
			parent[v.first] = u;
			int aux = dfs (v.first, u);
			qtd += aux;
			if (aux > bigger)
			{
				heavy[u] = v.first;
				bigger = aux;
			}
		}
	}
	
	return qtd;
}

int curPos;

void decompose (int u, int tree)
{
	head[u] = tree;
	pos[u] = curPos++;

	if (heavy[u] != -1) decompose (heavy[u], tree);
	
	for (int i = 0; i < (int)AdjList[u].size (); i++)
	{
		ii v = AdjList[u][i];
		if (v.first != parent[u] && v.first != heavy[u])
		{
			decompose (v.first, v.first);
		}
	}
}

int queryHLD (int a, int b)
{
	int res = 0;
	while (head[a] != head[b])
	{
		if (h[head[b]] > h[head[a]]) swap (a, b);
		
		res = max (res, query (1, 0, n - 1, pos[head[a]], pos[a]));
		
		a = parent[head[a]];
	}
	
	if (h[b] > h[a]) swap (a, b);
	
	res = max (res, query (1, 0, n - 1, pos[b] + 1, pos[a]));
	return res;
}

void updateHLD (int a, int b, int val)
{
	while (head[a] != head[b])
	{
		if (h[head[b]] > h[head[a]]) swap (a, b);
		
		update (1, 0, n - 1, pos[head[a]], pos[a], val);
		
		a = parent[head[a]];
	}
	
	if (h[b] > h[a]) swap (a, b);
	
	update (1, 0, n - 1, pos[b] + 1, pos[a], val);
}

int main ()
{
	int q, a, b, c;
	scanf ("%d%d", &n, &m);
	map <ii, int> mp;
	set <ii> st;
	vector <pair <int, ii> > EdgeList;
	
	for (int i = 0; i < MAXN; i++) parentSet[i] = i;
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d%d",  &a, &b, &c);
		EdgeList.push_back (make_pair (c, ii (a - 1, b - 1)));
		mp[ii (min (a - 1, b - 1), max (a - 1, b - 1))] = c;
	}
	
	sort (EdgeList.begin (), EdgeList.end ());
	
	int sum = 0;
	
	for (int i = 0; i < m; i++)
	{
		a = EdgeList[i].second.first;
		b = EdgeList[i].second.second;
		
		if (findSet (a) != findSet (b))
		{
			AdjList[a].push_back (ii (b, EdgeList[i].first));
			AdjList[b].push_back (ii (a, EdgeList[i].first));
			unionSet (a, b);
			st.insert (ii (min (a, b), max (a, b)));
			sum += EdgeList[i].first;
		}
	}
	
	memset (heavy, -1, sizeof heavy);
	
	dfs (0, 0);
	decompose (0, 0);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)AdjList[i].size (); j++)
		{
			ii v = AdjList[i][j];
			updateHLD (i, v.first, v.second);
			//cout << "(" << v.first + 1 << ", " << v.second << ")" << " ";
		}
	}
	
	scanf ("%d", &q);
	
	for (int i = 0; i < q; i++)
	{
		scanf ("%d%d", &a, &b);
		a--, b--;
		
		if (st.find (ii (min (a, b), max (a, b))) == st.end ())
		{
			cout << sum - queryHLD (a, b) + mp[ii (min (a, b), max (a, b))] << endl;
		}
		else printf ("%d\n", sum);
	}
}
