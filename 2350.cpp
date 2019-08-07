#include <bits/stdc++.h>

using namespace std;

int b[500500], n, m;
vector <int> P;
vector <int> T[33];
bool ind[33][500500];

inline void kmpPreprocess ()
{
	int i = 0, j = -1; b[0] = -1;
	while (i < n)
	{
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

inline void kmpSearch (int val, int pos)
{
	int i = 0, j = 0;
	while (i < m)
	{
		while (j >= 0 && T[val][i] != P[j]) j = b[j];
		i++; j++;
		if (j == n)
		{
			//cout << i - j << endl;
			ind[pos][i - j] = true;
			j = b[j];
		}
	}
}

bool vis[33], vis2[33];

int main ()
{	
	string str;
	int v[500500];
	cin >> str;
	m = str.size ();
	
	for (int i = 0; i < m; i++) vis2[str[i] - 'a' + 1] = true;
	
	scanf ("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &v[i]);
		vis[v[i]] = true;
	}
	
	for (int i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str[j] == i) T[i - 'a' + 1].push_back (1);
			else T[i - 'a' + 1].push_back (0);
		}
	}
	
	for (int i = 1; i <= 26; i++)
	{
		if (vis[i])
		{
			P.clear ();
			for (int j = 0; j < n; j++)
			{
				if (v[j] == i) P.push_back (1);
				else P.push_back (0);
			}
			
			kmpPreprocess ();
			
			for (int j = 1; j <= 26; j++)
			{
				if (vis2[j]) kmpSearch (j, i);
			}
		}
	}

	int res = 0;
	
	for (int i = 0; i < m - n + 1; i++)
	{
		int cont = 0;
		for (int j = 1; j <= 26; j++)
		{
			if (vis[j])
			{
				if (ind[j][i]) cont++;
			}
			else cont++;
		}
		if (cont == 26) res++;
	}
	
	cout << res << endl;
}
