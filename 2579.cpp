#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
	lld l, c, x, y;
	
	while(scanf("%lld %lld %lld %lld", &l, &c, &x, &y)!=EOF)
	{
		if( (x*c+y)%2==0)
			puts("Direita");
		else
			puts("Esquerda");
	}
}
