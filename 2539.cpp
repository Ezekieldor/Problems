#include <bits/stdc++.h>
#define MAX_N 100010

using namespace std;

long long int ft[MAX_N];

int last (int x)
{
	return x & (-x);
}

void update (int pos, int value)
{
	for (int i = pos; i < MAX_N; i += last (i))
	{
		ft[i] += value;
	}
}

long long query (int pos)
{
	long long sum = 0;
	for (int i = pos; i > 0; i -= last (i))
	{
		sum += ft[i];
	}
	return sum;
}

int main ()
{
	int n, aux;
	long long int sum;
	int hash[200000];
	while (scanf ("%d", &n) != EOF)
	{
		memset (ft, 0, sizeof ft);
		for (int i = n; i > 0; i--)
		{
			scanf ("%d", &aux);
			hash[aux] = i;
			update (i, 1);
		}
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += query (hash[i]) - 1;
			update (hash[i], -1);
		}
		printf ("%lld\n", sum);
	}
}
