#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int gcd (ll a, ll b)
{
	return b == 0 ? a : gcd (b, a % b);
}

int main ()
{
	int n;
	long long int fib[100];
	
	fib[1] = 2;
	fib[2] = 3;
	
	for (int i = 3; i <= 40; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while (scanf ("%d", &n) != EOF)
	{
		ll d = 1LL << n;
		ll div = gcd (fib[n], d);
		printf ("%lld/%lld\n", fib[n] / div, d / div);
	}
}
