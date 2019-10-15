#include<bits/stdc++.h>
using namespace std;

#define maxn 200200
#define mod 1000000007ll
#define ll long long

struct S{
	short int L[40];
	int size;
	S() : size(0) {}
};

int k;
int m[maxn];
S st[4*maxn];

int cnt2;
inline S merge(S &a, S &b){
	S r2;
	int ss = a.size+b.size;
	int i1 = a.size-1;
	int i2 = b.size-1;
	int mn = min(k, ss);
	r2.size = mn;
	for (int i = 0; i < mn; i++){
		cnt2++;
		if (i1 >= 0 && i2 >= 0){
			if (a.L[i1] > b.L[i2]){
				r2.L[mn-i-1] = a.L[i1];
				i1--;
			}else{
				r2.L[mn-i-1] = b.L[i2];
				i2--;
			}
		}else if (i1 >= 0){
			r2.L[mn-i-1] = a.L[i1];
			i1--;
		}else{
			r2.L[mn-i-1] = b.L[i2];
			i2--;
		}
	}
	return r2;
}

void build(int no, int l, int r){
	if (l == r){
		if (m[l] != 0){
			st[no].size = 1;
			st[no].L[0] = m[l];
		}
		return;
	}
	int md = (l+r)/2;
	build(no*2, l, md);
	build(no*2+1, md+1, r);
	st[no] = merge(st[no*2], st[no*2+1]);
}

int cntq;
S query(int no, int l, int r, int i, int j){	
	cntq++;
	S ans;
	if (l > j || r < i)
		return ans;
	if (l >= i && r <= j)
		return st[no];
	int md = (l+r)/2;
	S a = query(no*2, l, md, i, j);
	S b = query(no*2+1, md+1, r, i, j);
	return  merge(a,b);	
}

int main (){
	int n, r, L, R;
	scanf("%d%d%d", &n, &k, &r);
	for (int i = 0; i < n; i++){
		scanf("%d", &m[i]);
	}
	build(1, 0, n-1);
	cnt2 = 0;
	for (int i = 0; i < r; i++){
		scanf("%d%d", &L, &R);
		S ans = query(1, 0, n-1, L-1, R-1);
		ll an = 1;
		if (ans.size == 0)
			an = 0;
		for (int j = ans.size-1; j >= 0; j--)
			an = ((ll)ans.L[j]*an)%mod;
		printf ("%d\n", (int)an);
	}
	//printf ("%d %d\n", cntq, cnt2);
}
