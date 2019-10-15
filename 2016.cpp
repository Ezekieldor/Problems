#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int n, m;


int main ()
{
	int val, b, ded;
	scanf ("%d%d", &n, &m);
	
	int res = 0;
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d", &b);
		scanf ("%d", &ded);
		
		int sum = 0;
		
		for (int j = 1; j < n; j++)
		{
			scanf ("%d", &val);
			sum += val;
		}
		
		if (sum + ded <= b) res -= ded;
		
		if (sum + 10000 <= b) res += 10000;
		else if (sum + 1000 <= b) res += 1000;
		else if (sum + 100 <= b) res += 100;
		else if (sum + 10 <= b) res += 10;
		else if (sum + 1 <= b) res += 1;
	}
	
	printf ("%d\n", res);
}
