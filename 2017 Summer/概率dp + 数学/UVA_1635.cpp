#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 100005;
typedef long long LL;
int fac[100][2];
int n, m;
int now[100];
int ansNode[maxn];

void getFac(int m) {
	int res = m;
	int cnt = 0;
	for(int i = 2; i * i <= m; i++) {
		if(res < i) break;
		if(res % i == 0) {
			fac[++cnt][0] = i;
			while(res % i == 0) {
				res /= i;
				fac[cnt][1]++;
			}
		}
	}
	if(res > 1) {
		fac[++cnt][0] = res;
		fac[cnt][1] = 1;
	}
	fac[0][0] = cnt;
}

bool judge(int k) {
	int num = fac[0][0];
	int a = n - k + 1;
	int b = k;
	for(int i = 1; i <= num; i++) {
		int p = fac[i][0];
		while(a % p == 0) {
			now[i]++;
			a /= p;
		}
		while(b % p == 0) {
			now[i]--;
			b /= p;
		}
	}
	for(int i = 1; i <= num; i++) {
		if(now[i] < fac[i][1]) return false;
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		mem(fac, 0);
		getFac(m);
		mem(now, 0);
		n--;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(judge(i)) ansNode[++ans] = i + 1;
		}
		printf("%d\n", ans);
		for(int i = 1; i <= ans; i++) {
			printf("%d", ansNode[i]);
			if(i != ans) printf(" ");
		}
		puts("");
	}
	return 0;
}
