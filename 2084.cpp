#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n, vet[100];
	bool tr = false;
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &vet[i]);
	}
	
	double sum = 0;
	
	for (int j = 0; j < n; j++)
	{
		sum += vet[j];
	}
	
	for (int i = 0; i < n; i++)
	{
		if (vet[i] / sum * 100 >= 45)
		{
			tr = true;
			break;
		}
	}
	
	if (!tr)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (vet[i] / sum * 100 >= 40)
			{
				int j;
				for (j = 0; j < n; j++)
				{
					if (j != i)
					{
						if (vet[i] / sum * 100 - vet[j] / sum * 100 < 10) break;
					}
				}
				if (j == n)
				{
					printf ("1\n");
					break;
				}
			}
		}
		if (i == n)
		{
			printf ("2\n");
		}
	}
	else printf ("1\n");
}
