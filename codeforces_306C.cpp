#include <bits/stdc++.h>
#define maxn 8000
#define MOD 1000000009
#define LL long long
using namespace std;
int C[maxn + 100][maxn + 100];
int A[maxn + 100];

void init() {
	memset(C, 0, sizeof(C));
	memset(A, 0, sizeof(A));
	for(int i = 0; i <= maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	A[0] = 1;
	for(int i = 1; i <= maxn; i++) A[i] = (1LL * A[i - 1] * i) % MOD;
}

int main() {
	init();
	int n, w, b;
	LL ans = 0;
	cin >> n >> w >> b;
	for(int i = 1; i < w; i++) {
		ans += (1LL * C[w + b - 3][n - 3] * C[w][i] % MOD * A[i] % MOD * A[b] % MOD * A[w - i] % MOD) % MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
