#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000010

using namespace std;

typedef vector <int> vi;

int main ()
{	
	//freopen ("in.txt", "r", stdin);
	
	int a, b, c;
	
	scanf ("%d%d%d", &a, &b, &c);
	
	if (a == b || a == c || b == c || a + b == c || a + c == b || b + c == a) printf ("S\n");
	else printf ("N\n");
}
