#include <bits/stdc++.h>
#define INF 1234567899
#define ll long long int
#define mod 1000000007

using namespace std;

int V, n, m, v[1000];
ll dp[11100];

ll f (int val)
{
	if (val >= n) return 1;
	
	ll &p = dp[val];
	
	if (p != -1) return p;
	
	p = 0;
	
	for (int i = 0; i < m; i++)
	{
		p += f (val + v[i]);
		if (p > mod) p %= mod; 
	}
	
	return p;
}

int main ()
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d%d", &n, &m);
		
		for (int i = 0; i < m; i++)
		{
			scanf ("%d", &v[i]);
		}
		
		memset (dp, -1, sizeof dp);
		
		ll res = f (0);
		
		printf ("%lld\n", res);
	}
}
