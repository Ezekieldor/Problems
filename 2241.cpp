#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

int main ()
{
	//freopen ("in.txt", "r", stdin);
	
	int n, p, sum1[555][555], sum2[555][555], a, b, m[555][555];
	
	scanf ("%d%d", &n, &p);
	
	for (int i = 0; i < p; i++)
	{
		scanf ("%d%d", &a, &b);
		m[a][b] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + m[i][j];
			m[i][j] = 0;
		}
	}
	
	for (int i = 0; i < p; i++)
	{
		scanf ("%d%d", &a, &b);
		m[a][b] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + m[i][j];
			
		}
	}
	
	int v1 = p, v2 = p;
	
	for (int k = 2; k <= n; k++)
	{
		for (int i = k; i <= n; i++)
		{
			for (int j = k; j <= n; j++)
			{
				int a = sum1[i][j] + sum1[i - k][j - k] - sum1[i - k][j] - sum1[i][j - k];
				int b = sum2[i][j] + sum2[i - k][j - k] - sum2[i - k][j] - sum2[i][j - k];
				if (a > 0 && b == 0) v1++;
				else if (a == 0 && b > 0) v2++;
			}
		}
	}
	
	printf ("%d %d\n", v1, v2);
}
