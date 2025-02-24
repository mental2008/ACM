// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int maxn = 1005;
string s;
int k;
const int p = 1000;
int convert[maxn];
int n;

int bit(int x) {
	int cnt = 0;
	while (x) {
		if (x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}

int dp[maxn];

LL tp[maxn][maxn];

LL dfs(int pos, int num, bool flag) {
	if (pos == n) {
		if (dp[num] == k - 1) return 1;
		else return 0;
	}
	if (!flag && tp[pos][num] != -1) return tp[pos][num];
	int p;
	LL res = 0;
	if (flag) p = (s[pos] - '0');
	else p = 1;
	for (int i = 0; i <= p; ++i) {
		res = (res + dfs(pos + 1, num + i, flag && i == p)) % MOD;
	}
	if(!flag) tp[pos][num] = res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = p; i >= 2; --i) {
		convert[i] = bit(i);
	}
	dp[0] = -1;
	dp[1] = 0;
	for (int i = 2; i <= p; ++i) {
		dp[i] = dp[convert[i]] + 1;
	}
	cin >> s >> k;
	if (k == 0) cout << 1 << '\n';
	else if (k >= 6) cout << 0 << '\n';
	else {
		n = s.size();
		LL ans = 0;
		memset(tp, -1, sizeof(tp));
		ans = (ans + dfs(0, 0, 1)) % MOD;
		if (k == 1) ans--;
		ans = (ans % MOD + MOD) % MOD;
		cout << ans << '\n';
		
	}
    return 0;
}

