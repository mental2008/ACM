#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 100100
using namespace std;
vector<int> vec[maxn];
vector<int> dis[maxn];
queue<int> que;
bool exist[maxn];
int ans[maxn];

int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; i++) {
		int ui, vi, len;
		scanf("%d%d%d", &ui, &vi, &len);
		vec[ui].push_back(vi);
		dis[ui].push_back(len);
		vec[vi].push_back(ui);
		dis[vi].push_back(len);
	}
	memset(exist, 0, sizeof(exist));
	memset(ans, 0x3f, sizeof(ans));
	ans[s] = 0;
	exist[s] = 1;
	que.push(s);
	while(!que.empty()) {
		int u = que.front();
		exist[u] = 0;
		que.pop();
		for(int i = 0; i < vec[u].size(); i++) {
			int v = vec[u][i];
			if(ans[v] > ans[u] + dis[u][i]) {
				ans[v] = ans[u] + dis[u][i];
				if(!exist[v]) {
					que.push(v);
				}
			}
		}
	}
	printf("%d\n", ans[t]);
	return 0;
}
