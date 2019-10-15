#include <bits/stdc++.h>

using namespace std;


int main()
{
	int i, A, B,  aux, ans, vet[100];
	string a, b, op, c;
	
	cin >> a >> op >> b;
	
	
	for(i=0; i<(int)a.size(); i++)
		if(a[i]=='7')
			a[i] = '0';
	for(i=0; i<(int)b.size(); i++)
		if(b[i]=='7')
			b[i] = '0';
	
	A = B = 0;
	for(i=0; i<(int)a.size(); i++)
		A = A*10 + a[i]-'0';
	for(i=0; i<(int)b.size(); i++)
		B = B*10 + b[i]-'0';
		
	if(op=="+")
	{
		ans = A+B;
	}
	else
		ans = A*B;
	
	
	i = 0;
	aux = ans;
	while(aux)
	{
		vet[i++] = aux%10;
		aux/=10;
	}
	
	ans = 0;
	for(i--; i>-1; i--)
	{
		ans = ans*10;
		if(vet[i] != 7)
			ans += vet[i];
	}
	
	printf("%d\n", ans);
}
