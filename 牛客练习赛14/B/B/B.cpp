// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define mem(a, i) memset(a, i, sizeof(a))
typedef long long LL;
const int maxn = 1000005;
int n, m;
LL k;
LL a[maxn];
LL sum[maxn];
LL st[maxn][25];

int main()
{
	while (~scanf("%d%d%lld", &n, &m, &k)) {
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			sum[i] = a[i] + sum[i - 1];
		}
		mem(st, 0);
		for (int i = 1; i <= n; ++i) {
			int l = i, r = n;
			int res = i - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (sum[mid] - sum[i - 1] <= k) {
					res = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (i <= res) st[i][0] = res + 1;
		}
		for (int i = 1; i <= 20; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (st[j][i - 1] == 0) continue;
				st[j][i] = st[st[j][i - 1]][i - 1];
			}
		}
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = 0;
			for (int i = 20; i >= 0; --i) {
				if (st[l][i] == 0) continue;
				if (st[l][i] - 1 <= r) {
					l = st[l][i];
					ans += (1 << i);
				}
			}
			if (l <= r) {
				if (st[l][0] == 0) {
					puts("Chtholly");
					continue;
				}
				else ans++;
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}

