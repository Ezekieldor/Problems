#include <bits/stdc++.h>
#define ll long long int
#define mod 1073741824

using namespace std;

vector <ll> prime;

void sieve ()
{
	bitset <10000100> bs;
	bs.set ();
	
	for (ll i = 2; i < 10000100; i++)
	{
		if (bs[i])
		{
			prime.push_back (i);
			
			for (ll j = i * i; j < 10000100; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}

vector <int> f;

void fac (ll val)
{
	int k = 0;
	while (prime[k] * prime[k] <= val)
	{
		bool tr = false;
		while (val % prime[k] == 0)
		{
			val /= prime[k];
			tr = true;
		}
		if (tr) f.push_back (prime[k]);
		k++;
	}
	
	if (val != 1) f.push_back (val);
}

int main ()
{
	sieve ();
	ll n;
	
	scanf ("%lld", &n);
	
	fac (n);
	
	printf ("%lld\n", (ll)pow (2, (int)f.size ()) - (ll)f.size () - 1);
}
