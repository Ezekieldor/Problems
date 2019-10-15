#include<bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int main (){
	int n, m, k, p;
	char l;
	scanf("%d%d%d", &n, &m, &k);
	ii s1[n], s2[m];
	for (int i = 0; i < n; i++){
		s1[i] = ii(-1,-1);
	}
	for (int i = 0; i < m; i++)
		s2[i] = ii(-1,-1);
	for (int i = 0; i < k; i++){
		cin >> l >> p;
		if (l == 'C'){
			s2[p-1] = ii(i%4,i);
		}else
			s1[p-1] = ii(i%4,i);
	}
	int T[n][m];
	memset(T,-1,sizeof T);
	int cnt[4] = {0};
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			T[i][j] = s1[i].second > s2[j].second ? s1[i].first : s2[j].first;
			if (T[i][j] != -1)
				cnt[T[i][j]]++;
		}
	}
	printf ("R%d H%d C%d P%d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
}
