#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

int ordR[] = {-1, 0, 1, 0};
int ordC[] = {0, 1, 0, -1};
int n, m, v[222][222];

int flood (int r, int c, int val)
{
	if (r < 0 || r == n || c < 0 || c == m) return 0;
	if (v[r][c] != val) return 0;
	v[r][c] = -1;
	
	int p = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int a = ordR[i] + r, b = ordC[i] + c;
		p += flood (a, b, val);
	}
	
	return p + 1;
}

int main ()
{
	//freopen ("in.txt", "r", stdin);
	string bi[20], r, g, b, R, G, B;
	ll vR = 0, vG = 0, vB = 0;

	bi[0] = "0000";
	bi[1] = "0001";
	bi[2] = "0010";
	bi[3] = "0011";
	bi[4] = "0100";
	bi[5] = "0101";
	bi[6] = "0110";
	bi[7] = "0111";
	bi[8] = "1000";
	bi[9] = "1001";
	bi[10] = "1010";
	bi[11] = "1011";
	bi[12] = "1100";
	bi[13] = "1101";
	bi[14] = "1110";
	bi[15] = "1111";
	
	cin >> r >> g >> b;
	
	for (int i = 0; i < (int)r.size (); i++)
	{
		if (r[i] == 'a') R += bi[10];
		else if (r[i] == 'b') R += bi[11];
		else if (r[i] == 'c') R += bi[12];
		else if (r[i] == 'd') R += bi[13];
		else if (r[i] == 'e') R += bi[14];
		else if (r[i] == 'f') R += bi[15];
		else R += bi[r[i] - '0'];
	}
	
	for (int i = 0; i < (int)g.size (); i++)
	{
		if (g[i] == 'a') G += bi[10];
		else if (g[i] == 'b') G += bi[11];
		else if (g[i] == 'c') G += bi[12];
		else if (g[i] == 'd') G += bi[13];
		else if (g[i] == 'e') G += bi[14];
		else if (g[i] == 'f') G += bi[15];
		else G += bi[g[i] - '0'];
	}
	
	for (int i = 0; i < (int)b.size (); i++)
	{
		if (b[i] == 'a') B += bi[10];
		else if (b[i] == 'b') B += bi[11];
		else if (b[i] == 'c') B += bi[12];
		else if (b[i] == 'd') B += bi[13];
		else if (b[i] == 'e') B += bi[14];
		else if (b[i] == 'f') B += bi[15];
		else B += bi[b[i] - '0'];
	}
	
	for (int i = (int)R.size () - 1, pw = 1; i >= 0; i--, pw *= 2) vR += pw * (R[i] - '0');
	for (int i = (int)G.size () - 1, pw = 1; i >= 0; i--, pw *= 2) vG += pw * (G[i] - '0');
	for (int i = (int)B.size () - 1, pw = 1; i >= 0; i--, pw *= 2) vB += pw * (B[i] - '0');
	
	ll v1 = (vR / vG) * (vR / vG);
	ll val = (vG / vB) * (vG / vB) * v1 + v1 + 1;
	
	string res;
	
	while (val >= 16)
	{
		ll aux = val % 16;
		if (aux == 10) res += 'a';
		else if (aux == 11) res += 'b';
		else if (aux == 12) res += 'c';
		else if (aux == 13) res += 'd';
		else if (aux == 14) res += 'e';
		else if (aux == 15) res += 'f';
		else res += aux + '0';
		val /= 16;
	}
	
	ll aux = val;
	if (aux == 10) res += 'a';
	else if (aux == 11) res += 'b';
	else if (aux == 12) res += 'c';
	else if (aux == 13) res += 'd';
	else if (aux == 14) res += 'e';
	else if (aux == 15) res += 'f';
	else res += aux + '0';
	
	reverse (res.begin (), res.end ());
	
	cout << res << endl;
}
