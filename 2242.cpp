#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

int main ()
{	
	//freopen ("in.txt", "r", stdin);
	
	string str, res, aux;
	
	cin >> str;
	
	for (int i = 0; i < (int)str.size (); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') res += str[i];
	}
	
	aux = res;
	
	reverse (aux.begin (), aux.end ());
	
	if (aux == res) printf ("S\n");
	else printf ("N\n");
}
