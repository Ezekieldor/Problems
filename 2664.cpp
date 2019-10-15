#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

ll dp[55][100010];
int n, up, down;

ll f (int item, int val)
{
	if (item == n) return 1;
	
	ll &p = dp[item][val];
	
	if (p != -1) return p;
	
	p = 0;
	
	if (val < up) p += f (item + 1, val + 1);
	if (val > down) p += f (item + 1, val - 1);
	
	p %= mod;
	
	return p;
}

int main ()
{	
	scanf ("%d%d%d", &n, &down, &up);
	
	ll res = 0;
	
	memset (dp, -1, sizeof dp);
	
	for (int i = down; i <= up; i++)
	{
		res += f (1, i);
		res %= mod;
	}
	
	printf ("%lld\n", res);
}
