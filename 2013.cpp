#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int n;
string str;
ll dp[20][2][2][2][2][2][2][2][2][2][2][2];

ll f (int item, ll val, bool tr, int n0, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9)
{
	if (item == n) return val;
	
	ll &p = dp[item][tr][n0][n1][n2][n3][n4][n5][n6][n7][n8][n9];
	
	if (p != -1) return p;
	p = 0;
	vector <int> v, a (10, 0);
	
	v.push_back (n0);
	v.push_back (n1);
	v.push_back (n2);
	v.push_back (n3);
	v.push_back (n4);
	v.push_back (n5);
	v.push_back (n6);
	v.push_back (n7);
	v.push_back (n8);
	v.push_back (n9);
	
	if (!tr)
	{
		for (int i = str[item] - '0'; i >= 0; i--)
		{
			if (v[i] < 2)
			{
				a[i]++;
				if (i == str[item] - '0') p = max (p, f (item + 1, val * 10 + i, false, n0 + a[0], n1 + a[1], n2 + a[2], n3 + a[3], n4 + a[4], n5 + a[5], n6 + a[6], n7 + a[7], n8 + a[8], n9 + a[9]));
				else p = max (p, f (item + 1, val * 10 + i, true, n0 + a[0], n1 + a[1], n2 + a[2], n3 + a[3], n4 + a[4], n5 + a[5], n6 + a[6], n7 + a[7], n8 + a[8], n9 + a[9]));
				a[i]--;
			}
		}
	}
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			if (v[i] < 2)
			{
				a[i]++;
				p = max (p, f (item + 1, val * 10 + i, tr, n0 + a[0], n1 + a[1], n2 + a[2], n3 + a[3], n4 + a[4], n5 + a[5], n6 + a[6], n7 + a[7], n8 + a[8], n9 + a[9]));
				a[i]--;
			}
		}
	}
	
	return p;
}

int aux[10];

int main ()
{
	
	cin >> str;
	n = str.size ();
	
	memset (dp, -1, sizeof dp);
	
	printf ("%lld\n", f (0, 0, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
}
