#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n;
vector<int> vec[maxn];
int vis[maxn];
int dis;
int endpoint;
int score1;

bool dfs(int i, int count) {
	if(i == n) {
		dis = count;
		return true;
	}
	for(int j = 0; j < vec[i].size(); j++) {
		if(!vis[vec[i][j]]) {
			vis[vec[i][j]] = 1;
//			printf("%d\n", vec[i][j]);
			if(dfs(vec[i][j], count + 1)) {
				if(count + 1 == (dis + 1) / 2 + 1) {
					endpoint = vec[i][j];
				}
				return true;
			}
		}
	}
	return false;
} 

void Fennec(int i) {
	for(int j = 0; j < vec[i].size(); j++) {
		if(!vis[vec[i][j]]) {
			if(vec[i][j] == endpoint) continue;
			else {
				vis[vec[i][j]] = 1;
				score1++;
				Fennec(vec[i][j]);
			}
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) vec[i].clear();
		memset(vis, 0, sizeof(vis));
		dis = -0x3f3f3f3f;
		endpoint = 0;
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		vis[1] = 1;
		dfs(1, 1);
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		score1 = 1;
		Fennec(1);
//		printf("%d\n", endpoint);
		if(score1 > n - score1) puts("Fennec");
		else puts("Snuke");
	}
	return 0;
} 
