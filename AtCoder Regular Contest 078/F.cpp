#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 20;
vector<int> vec[maxn];
vector<int> cost[maxn];
bool vis[maxn];
int n, m;
LL ans;
LL sum;

void dfs(int node, LL value, int count) {
	if(node == n) {
		ans = min(ans, sum - value);
		return;
	}
	if(count == n && node != n) return;
	for(int i = 0; i < vec[node].size(); i++) {
		if(vis[vec[node][i]] == 0) {
			vis[vec[node][i]] = 1;
			dfs(vec[node][i], value + cost[node][i], count + 1);
			vis[vec[node][i]] = 0;
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i < maxn; i++) {
			vec[i].clear(), cost[i].clear();
		}
		sum = 0;
		for(int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			sum += c;
			vec[a].push_back(b);
			cost[a].push_back(c);
			vec[b].push_back(a);
			cost[b].push_back(c); 
		}
		memset(vis, 0, sizeof(vis));
		ans = 1e18;
		vis[1] = 1;
		dfs(1, 0, 1);
		printf("%lld\n", ans);
	}
	return 0;
}
