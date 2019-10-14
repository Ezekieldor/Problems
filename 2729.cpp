#include <bits/stdc++.h>

using namespace std;

int main ()
{
	string str;
	map <string, int> mp;
	map <string, int>::iterator it;
	int t;
	char c;
	
	scanf ("%d", &t);
	
	while (t--)
	{
		while (true)
		{
			cin >> str;
			mp[str]++;
			c = getchar ();
			if (c == '\n' || c == EOF) break;
		}
		it = mp.begin ();
		cout << it->first;
		it++;
		for (; it != mp.end (); ++it)
		{
			cout << " " << it->first;
		}
		puts ("");
		mp.clear ();
	}
}
