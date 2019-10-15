#include <bits/stdc++.h>
#define INF 1234567899
#define ll long long int

using namespace std;

int V, n;
long double dp[1100][6100];
long double pw; 

long double f (int item, int val)
{
	if (item == n) return (val >= V ? pw : 0);
	
	long double &p = dp[item][val];
	
	if (p != -1) return p;
	
	p = 0;
	
	for (int i = 1; i <= 6; i++)
	{
		if (val + i >= V) p += f (item + 1, V);
		else p += f (item + 1, val + i);
	}
	
	return p;
}

int main ()
{
	while (scanf ("%d%d", &n, &V) != EOF)
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < 6050; j++)
				dp[i][j] = -1;
		
		pw = 1;
		
		for (int i = 0; i < n; i++)
		{
			pw /= 6;
		}

		double res = f (0, 0);
		
		printf ("%.4lf\n", res);
	}
}
