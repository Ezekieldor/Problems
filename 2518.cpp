#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n, h, c, l;
	while (scanf ("%d", &n) != EOF)
	{
		scanf ("%d%d%d", &h, &c, &l);
		
		double H = (sqrt (c * c + h * h)) * n;
		
		printf ("%.4f\n", ((double)l * H) / 10000);
	}
}
