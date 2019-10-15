#include <bits/stdc++.h>

using namespace std;

int V, n, v[1100];

bool f (int item, int disp)
{
	if (disp == 0) return true;
	if (item == n) return false;
	
	if (disp >= v[item])
	{
		return f (item + 1, disp - v[item]) || f (item + 1, disp);
	}
	return f (item + 1, disp);
}

int main ()
{

	while (scanf ("%d%d", &V, &n), V)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d", &v[i]);
		}
		
		if (f (0, V)) printf ("sim\n");
		else printf ("nao\n");
	}
}
