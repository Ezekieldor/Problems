#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int v[3], t;
	string str;
	
	scanf ("%d", &t);
	
	while (t--)
	{
		cin >> str;
		
		for (int i = 0, k = 0; i < (int)str.size ();)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				v[k] = 0;
				while (str[i] >= '0' && str[i] <= '9')
				{
					v[k] = v[k] * 10 + (str[i++] - '0');
				}
				k++;
			}
			else i++;
		}
		
		printf ("%d\n", v[0] + v[1] + v[2]);
	}
}
