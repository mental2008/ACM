// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
const LL MOD = 998244353;
string s[maxn];
int nxt[2 * maxn];

LL KMP(string pattern, string text) {
	int n = pattern.size();
	nxt[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0) {
			j = nxt[j];
			if (pattern[j] == pattern[i]) {
				nxt[i + 1] = j + 1;
				break;
			}
		}
	}
	LL res = 0;
	int m = text.size();
	for (int i = 0, j = 0; i < m; ++i) {
		if (j < n && text[i] == pattern[j]) {
			j++;
		}
		else {
			while (j > 0) {
				j = nxt[j];
				if (text[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
		if (j == n) res++;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
		}
		for (int i = 1; i <= n; ++i) {
			LL ans = 1;
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				if (s[i].size() > s[j].size()) {
					ans = 0;
					break;
				}
				ans = (ans * KMP(s[i], s[j])) % MOD;
				if (ans == 0) break;
			}
			cout << ans << '\n';
		}
	}
    return 0;
}

