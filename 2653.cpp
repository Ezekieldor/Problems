#include <bits/stdc++.h>

using namespace std;

int main ()
{
	string str;
	map <string, bool> mp;
	
	while (cin >> str) mp[str] = true;
	
	printf ("%d\n", (int)mp.size ());
}
