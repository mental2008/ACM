#include <bits/stdc++.h>
#define LL long long
#define maxn 200000 + 100
#define MOD 1000000007
using namespace std;
char s[maxn];
int l[maxn];
int r[maxn];
int A[2 * maxn];

void extendGcd(LL a, LL b, LL &x, LL &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		extendGcd(b, a % b, x, y);
		LL tmp = x;
		x = y;
		y = tmp - a / b * y;
		return;
	}
}

int cal(int n, int m) {
	LL a = (1LL * A[n] * A[m - n]) % MOD;
	LL t, x;
	extendGcd(a, MOD, t, x);
	while(t < 0) t += MOD;
	t %= MOD;
	return (1LL * A[m] * t) % MOD;
}

int main() {
	cin >> s;
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	memset(A, 0, sizeof(A));
	A[0] = 1;
	for(int i = 1; i <= 400000; i++) A[i] = (1LL * A[i - 1] * i) % MOD;
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(i == 0) l[i] = (int)(s[i] == '(');
		else l[i] += l[i - 1] + (int)(s[i] == '(');
	}
	for(int i = len - 1; i >= 0; i--) {
		if(i == len - 1) r[i] = (int)(s[i] == ')');
		else r[i] += r[i + 1] + (int)(s[i] == ')');
	}
	LL ans = 0;
	for(int i = 0; i < len; i++) {
		if(s[i] == '(') {
			ans += cal(r[i] - 1, r[i] + l[i] - 1);
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
