#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int t, n, cont;
	scanf ("%d", &t);
	char aux, c;
	while (t--)
	{
		scanf ("%d", &n);
		cont = 0;
		for (int i = 0; i < n; i++)
		{
			scanf (" %c", &c);
			if (c - 'A' != i) cont++;
			aux = c;
		}
		
		if (cont <= 2) printf ("There are the chance.\n");
		else printf ("There aren't the chance.\n");
	}
}
