#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2005;
int n, m;
vector<int> G[maxn];
bool mark[maxn];
int s[maxn], c;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	memset(mark, 0, sizeof(mark));
	memset(s, 0, sizeof(s));
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

int main() {
	while(~scanf("%d", &n)) {
		init();
		scanf("%d", &m);
		for(int i = 1; i <= m; i++) {
			int a1, a2, c1, c2;
			scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
			G[2 * a1 + c1].push_back((2 * a2 + c2) ^ 1);
			G[2 * a2 + c2].push_back((2 * a1 + c1) ^ 1);
		}
		bool ans = solve();
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}//2-SAT
