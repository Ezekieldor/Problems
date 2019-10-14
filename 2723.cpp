#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

int n;

int v[MAXN];

int f (int item, int a, int b)
{
	if (fabs (a - b) > 5) return false;
	if (item == n) return true;

	return (f (item + 1, a + v[item], b) || f (item + 1, a, b + v[item]));
}

int main ()
{
	int t;
	
	scanf ("%d", &t);
	
	while (t--)
	{
		scanf ("%d", &n);
		
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &v[i]);
		}
		
		bool res = f (0, 0, 0);
		
		printf ("%s\n", (res ? "Feliz Natal!" : "Ho Ho Ho!"));
	}
}
