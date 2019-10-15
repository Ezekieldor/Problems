#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll sum[5000][5000];

int main ()
{
	int n, g, val;
	scanf ("%d%d", &n, &g);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf ("%d", &val);
			sum[i][j] = val + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	
	for (int k = 1; k <= n / 2; k++)
	{
		if (n % k == 0)
		{
			bool tr = false;
			for (int i = k; i <= n; i += k)
			{
				for (int j = k; j <= n; j += k)
				{
					if (sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] < g)
					{
						tr = true;
						break;
					}
				}
				if (tr) break;
			}
			
			if (!tr)
			{
				printf ("%d\n", (n / k) * (n / k));
				return 0;
			}
		}
	}
	
	printf ("1\n");
}
