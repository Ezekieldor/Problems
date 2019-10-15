#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int parent[1010];

int findSet (int x)
{
	if (parent[x] == x) return x;
	return parent[x] = findSet (parent[x]);
}

void unionSet (int x, int y)
{
	x = findSet (x);
	y = findSet (y);
	
	parent[y] = x;
}

int main ()
{
	int K = 1, n, m, a, b, c;
	
	while (scanf ("%d%d", &n, &m), n)
	{
		for (int i = 0; i < 111; i++) parent[i] = i;
		vector <pair <int, ii> > EdgeList;
		
		for (int i = 0; i < m; i++)
		{
			scanf ("%d%d%d", &a, &b, &c);
			EdgeList.push_back (make_pair (c, ii (a - 1, b - 1)));
		}
		
		sort (EdgeList.begin (), EdgeList.end ());
		
		printf ("Teste %d\n", K++);
		
		for (int i = 0; i < m; i++)
		{
			if (findSet (EdgeList[i].second.first) != findSet (EdgeList[i].second.second))
			{
				unionSet (EdgeList[i].second.first, EdgeList[i].second.second);
				if (EdgeList[i].second.first < EdgeList[i].second.second)
					cout << EdgeList[i].second.first + 1 << " " << EdgeList[i].second.second + 1 << endl;
				else cout << EdgeList[i].second.second + 1 << " " << EdgeList[i].second.first + 1 << endl;
			}
		}
		puts ("");
	}
}
