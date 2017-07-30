#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2005;
vector<int> G[2 * maxn];
bool mark[2 * maxn];
int s[2 * maxn], c;
int n;
int T[maxn][2];

void init() {
	for(int i = 0; i < 2 * maxn; i++) G[i].clear();
	memset(mark, 0, sizeof(mark));
	memset(s, 0, sizeof(s));
	//memset(T, 0, sizeof(T));
}

bool dfs(int x) {
	if(mark[x ^ 1]) return false;
	if(mark[x]) return true;
	mark[x] = true;
	s[c++] = x;
	for(int i = 0; i < G[x].size(); i++)
		if(!dfs(G[x][i])) return false;
	return true;
}

bool solve() {
	for(int i = 0; i < 2 * n; i += 2) {
		if(!mark[i] && !mark[i + 1]) {
			c = 0;
			if(!dfs(i)) {
				while(c > 0) mark[s[--c]] = false;
				if(!dfs(i + 1)) return false;
			}
		}
	}
	return true;
}

bool test(int diff) {
	init();
	for(int i = 0; i < n; i++) {
		for(int a = 0; a < 2; a++) {
			for(int j = i + 1; j < n; j++) {
				for(int b = 0; b < 2; b++) {
					if(abs(T[i][a] - T[j][b]) < diff) {
						G[2 * i + a].push_back((2 * j + b) ^ 1);
						G[2 * j + b].push_back((2 * i + a) ^ 1);
					}
				}
			}
		}
	}
	return solve();
}

int main() {
	while(~scanf("%d", &n)) {
		int L = 0, R = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2; j++) {
				scanf("%d", &T[i][j]);
				R = max(R, T[i][j]);
			}
		}
		int ans = 0;
		while(L <= R) {
			int mid = (L + R) / 2;
			if(test(mid)) {
				ans = max(ans, mid);
				L = mid + 1;
			}
			else R = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
