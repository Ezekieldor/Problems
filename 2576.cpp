#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int dks (int s, int t, vii AdjList[])
{
	priority_queue <ii, vii, greater <ii> > pq;
	pq.push (ii (0, s));
	vi dist (10100, INF);
	dist[s] = 0;
	
	while (!pq.empty ())
	{
		int u = pq.top ().second;
		pq.pop ();
		
		for (int i = 0; i < (int)AdjList[u].size (); i++)
		{
			ii v = AdjList[u][i];
			if (dist[v.first] > dist[u] + v.second)
			{
				dist[v.first] = dist[u] + v.second;
				pq.push (ii (dist[v.first], v.first));
			}
		}
	}
	
	return dist[t];
}

int main ()
{
	int n, m, a, b, x, y;
	vii AdjList1[10100], AdjList2[10100];
	scanf ("%d%d%d%d", &n, &m, &a, &b);
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d", &x, &y);
		AdjList1[x - 1].push_back (ii (y - 1, 0));
		AdjList1[y - 1].push_back (ii (x - 1, 1));
		
		AdjList2[x - 1].push_back (ii (y - 1, 0));
		AdjList2[y - 1].push_back (ii (x - 1, 1));
	}
	
	int v1 = dks (a - 1, b - 1, AdjList1), v2 = dks (b - 1, a - 1, AdjList2);
	
	//cout << v1 << " " << v2 << endl;
	
	if (v1 < v2) printf ("Bibi: %d\n", v1);
	else if (v1 > v2) printf ("Bibika: %d\n", v2);
	else printf ("Bibibibika\n");
}
