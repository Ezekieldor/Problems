#include <bits/stdc++.h>
#define INF 1234567899

using namespace std;

int dp[1100][1101], vet[1100], n, h;

int f (int item, int val)
{
	int v = vet[item] + val;

	if (item == n - 2)
	{
		return (v <= h ? 0 : INF);
	}
	
	int &p = dp[item][val];
	
	if (p != -1) return p;
	
	if (v < h) p = min (1 + f (item + 1, v - h), f (item + 1, 0));
	else if (v > h) p = 1 + f (item + 1, v - h);
	else p = f (item + 1, 0);
	
	return p;
}

int main ()
{
	while (scanf ("%d%d", &n, &h))
	{
		if (n == -1 && h == -1) break;
		
		for (int i = 0; i < n - 1; i++)
		{
			scanf ("%d", &vet[i]);
		}
		memset (dp, -1, sizeof dp);
		
		int res = f (0, 0);
		cout << (res < 1234567 ? res : -1) << endl;
	}
}
