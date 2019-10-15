#include <bits/stdc++.h>
using namespace std;
int N,Wei;
int Valor [1010];

bool cetinha (int W, int item)
{
    if (W == 0) return true;
    if (item == N) return false;
    
    bool p = false;
    
	
	p = false;
	
    if (W >= Valor[item])
    {
        p = cetinha (W - Valor[item], item + 1 ) || cetinha (W, item + 1);

    }
    else p = cetinha (W, item + 1);

    return p;
}

int main()
{
    scanf("%d %d",&Wei,&N);
    
	for (int i = 0 ; i < N ; i++)
	{
		scanf("%d",&Valor[i]);
	}
	cetinha (Wei, 0) ? puts("S") : puts("N");
    
    return 0;
}
