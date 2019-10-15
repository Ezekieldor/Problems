#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int a, b, c, xC, yC, xF;
	float resul, x, y, res;
	while (scanf ("%d%d%d", &a, &b, &c) != EOF)
	{
		scanf ("%d%d", &xC, &yC);
		scanf ("%d", &xF);
		resul = 123456789;
		for (int i = 0; i < xF; i++)
		{
			for (double j = 0.001; j < 1; j += 0.001)
			{
				x = i + j;
				y = -x * x / a - x / b + c;
				res = sqrt ((float)pow (x - xC, 2) + (float)pow (y - yC, 2));
				resul = min (res, resul);
			}
		}
		printf ("%.2f\n", resul);
	}
}
