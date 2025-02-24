// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
char ch[5005];
bool vis[5005][5005];
LL ans;
int len;
vector<int> vec2[5005];

void dfs(int l, int r) {
	if (vis[l][r]) return;
	vis[l][r] = 1;
	vec2[r].push_back(l);
	ans++;
	if (l > 0 && r < len - 1 && ((ch[l - 1] == '(' && ch[r + 1] == ')') || (ch[l - 1] == '(' && ch[r + 1] == '?') || (ch[l - 1] == '?' && ch[r + 1] == ')') || (ch[l - 1] == '?' && ch[r + 1] == '?'))) {
		dfs(l - 1, r + 1);
	}
	if (r < len - 2 && ((ch[r + 1] == '(' && ch[r + 2] == ')') || (ch[r + 1] == '(' && ch[r + 2] == '?') || (ch[r + 1] == '?' && ch[r + 2] == ')') || (ch[r + 1] == '?' && ch[r + 2] == '?'))) {
		dfs(l, r + 2);
	}
	if (l > 1 && ((ch[l - 2] == '(' && ch[l - 1] == ')') || (ch[l - 2] == '(' && ch[l - 1] == '?') || (ch[l - 2] == '?' && ch[l - 1] == ')') || (ch[l - 2] == '?' && ch[l - 1] == '?'))) {
		dfs(l - 2, r);
	}
	if (l - 1 >= 0) {
		int len2 = vec2[l - 1].size();
		for (int i = 0; i < len2; ++i) {
			dfs(vec2[l - 1][i], r);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> ch) {
		len = strlen(ch);
		ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 5005; ++i) vec2[i].clear();
		for (int i = 0; i + 1 < len; ++i) {
			if ((ch[i] == '(' && ch[i + 1] == ')') || (ch[i] == '(' && ch[i + 1] == '?') || (ch[i] == '?' && ch[i + 1] == ')') || (ch[i] == '?' && ch[i + 1] == '?')) {
				dfs(i, i + 1);
			}
		}
		cout << ans << '\n';
	}
    return 0;
}

