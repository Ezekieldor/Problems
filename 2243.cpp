//1 2 3 4 5 6 5 6 7 5 6 7

#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n, A[51010], v[51010];
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &v[i]);
	}

	int k = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] >= k) A[i] = k++;
		else A[i] = v[i], k = v[i] + 1;
	}
	
	k = 1;
	
	int res = 0;
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (A[i] >= k) res = max (res, k++);
		else res = max (res, A[i]), k = A[i] + 1;
	}

	printf ("%d\n", res);
}
