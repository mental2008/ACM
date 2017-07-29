#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 2010;
int n, m;
vector<int> G[maxn];

int main() {
	while(~scanf("%d", &n)) {
		scanf("%d", &m);
		ok = false;
		memset(rel, 0, sizeof(rel));
		for(int i = 0; i < m; i++) {
			int a1, a2, c1, c2;
			scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
			rel[2 * a1 + c1][2 * a2 + c2] = 1;
			rel[2 * a2 + c2][2 * a1 + c1] = 1;
		}
		dfs(0, 1);
		if(!ok) dfs(1, 1);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
} //2-SAT Î´Íê´ýÐø 
