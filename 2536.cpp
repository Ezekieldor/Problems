#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

struct ii
{
	int a, b, inst;
	
	ii (int in, int A, int B)
	{
		inst = in;
		a = A;
		b = B;
	}
	ii () {}
}
v[1000];
int n;
bool dp[110][500];

int f (int item, int r)
{
	if (item == n) return r;
	
	if (dp[item][r]) return INF;
	dp[item][r] = true;
	
	if (v[item].inst == 1) r += v[item].a;
	else if (v[item].inst == 2)
	{
		r -= v[item].a;
		if (r < 0) r += 256;
	}
	else if (v[item].inst == 3) r *= v[item].a;
	else if (v[item].inst == 4) r /= v[item].a;
	else if (v[item].inst == 5) r &= v[item].a;
	else if (v[item].inst == 6) r |= v[item].a;
	else if (v[item].inst == 7) r ^= v[item].a;
	else if (v[item].inst == 8)
	{
		if (r >= v[item].a) return f (v[item].b, r);
		return f (item + 1, r);
	}
	else return r;
	
	return f (item + 1, r % 256);
}

int main ()
{
	int a, b, pos;
	string inst;
	map <string, int> mp;
	
	mp["add"] = 1;
	mp["sub"] = 2;
	mp["mul"] = 3;
	mp["div"] = 4;
	mp["and"] = 5;
	mp["or"] = 6;
	mp["xor"] = 7;
	mp["gotoif"] = 8;
	mp["halt"] = 9;
	
	while (scanf ("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> pos >> inst;
			if (inst != "halt") scanf ("%d", &a);
			if (inst == "gotoif") scanf ("%d", &b);
			
			v[pos] = ii (mp[inst], a, b);
		}
		
		memset (dp, false, sizeof dp);
		
		int res = f (1, 0);
		
		if (res == INF) printf ("execucao infinita\n");
		else printf ("%d\n", res);
	}
}
