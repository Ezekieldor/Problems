#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 100000000000000000ll

typedef pair <ll, string> ls;

map<string, bool> dp;
int cost[8];

ll fun (string s)
{
	if (dp.find (s) != dp.end ()) return 0;
	
	//dp[s] = inf;
	ll ans = inf;
	string aux;
	for (int i = 0; i < 4; i++)
	{
		aux = s;
		swap(aux[i], aux[i + 4]);
		ll c = cost[(int)aux[i]] + cost[(int)aux[i+4]];
		ans = min(ans, fun(aux) + c);
	}
	for (int i = 0; i < 3; i++)
	{
		aux = s;
		swap(aux[i], aux[i+1]);
		ll c = cost[(int)aux[i]] + cost[(int)aux[i+1]];
		ans = min(ans, fun(aux) + c);
		aux = s;
		swap(aux[i+4], aux[i+5]);
		c = cost[(int)aux[i+4]] + cost[(int)aux[i+5]];
		ans = min(ans, fun(aux) + c);
	}
	//dp[s] = ans;
	return ans;
}

ll dks (string s, string t)
{
	string aux;
	map <string, ll> dist;
	dist[s] = 0;
	
	priority_queue <ls, vector <ls>, greater <ls> > pq;
	pq.push (ls (0, s));
	
	while (!pq.empty ())
	{
		string u = pq.top ().second;
		pq.pop ();
		
		for (int i = 0; i < 4; i++)
		{
			aux = u;
			swap (aux[i], aux[i + 4]);
			ll c = cost[(int)aux[i]] + cost[(int)aux[i + 4]];
			if (dist.find (aux) == dist.end ())
			{
				dist[aux] = dist[u] + c;
				pq.push (ls (dist[aux], aux));
			}
			else
			{
				if (dist[u] + c < dist[aux])
				{
					dist[aux] = dist[u] + c;
					pq.push (ls (dist[aux], aux));
				}
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			aux = u;
			swap(aux[i], aux[i+1]);
			ll c = cost[(int)aux[i]] + cost[(int)aux[i+1]];
			if (dist.find (aux) == dist.end ())
			{
				dist[aux] = dist[u] + c;
				pq.push (ls (dist[aux], aux));
			}
			else
			{
				if (dist[u] + c < dist[aux])
				{
					dist[aux] = dist[u] + c;
					pq.push (ls (dist[aux], aux));
				}
			}
			
			aux = u;
			swap(aux[i+4], aux[i+5]);
			c = cost[(int)aux[i+4]] + cost[(int)aux[i+5]];
			if (dist.find (aux) == dist.end ())
			{
				dist[aux] = dist[u] + c;
				pq.push (ls (dist[aux], aux));
			}
			else
			{
				if (dist[u] + c < dist[aux])
				{
					dist[aux] = dist[u] + c;
					pq.push (ls (dist[aux], aux));
				}
			}
		}
	}
	return dist[t];
}

int main ()
{
	int A[2][4];
	int X[1010];
	memset (X, -1, sizeof(X));
	int k = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &A[i][j]);
			cost[k] = A[i][j];
			X[A[i][j]] = k++;
		}
	string s, t;
	for (int i = 0; i < 8; i++)
	{
		int x;
		scanf("%d", &x);
		t += char(X[x]);
	}
	
	s = "";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
		{
			s += char(X[A[i][j]]);
		}
	printf ("%lld\n", dks (s, t));
}
