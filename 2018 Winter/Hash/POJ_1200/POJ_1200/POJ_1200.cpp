// POJ_1200.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 16000005;
int n, nc;
char s[maxn];
bool vis[maxn];
int convert[30];

int main()
{
	while (~scanf("%d%d", &n, &nc)) {
		memset(vis, 0, sizeof(vis));
		scanf("%s", s);
		int len = strlen(s);
		memset(convert, -1, sizeof(convert));
		int sign = 0;
		for (int i = 0; i < len; ++i) {
			if (convert[s[i] - 'a'] == -1) {
				convert[s[i] - 'a'] = sign++;
			}
		}
		int res = 0;
		int p = 1;
		for (int i = 0; i < n; ++i) {
			res = res * nc + convert[s[i] - 'a'];
			if (i != n - 1) p *= nc;
		}
		vis[res] = 1;
		int ans = 1;
		for (int i = 1; i + n - 1 < len; ++i) {
			res -= (p * convert[s[i - 1] - 'a']);
			res = res * nc + convert[s[i + n - 1] - 'a'];
			if (vis[res] == 0) {
				vis[res] = 1;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}

