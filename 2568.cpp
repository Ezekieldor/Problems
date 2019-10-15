#include<bits/stdc++.h>
using namespace std;

int main (){
	int d, i, x, f;
	scanf("%d%d%d%d", &d, &i, &x, &f);
	int init = 1;
	if (d%2 == 0)
		init = -1;
	for (int j = 0; j < f; j++){
		i = i+x*init;
		init = -init;
	}
	printf ("%d\n", i);
}
