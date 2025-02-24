// E.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 200005;
map<int, int> mp[maxn];
int n, m;
set<int> s;
vector<int> ans;
queue<int> q;
queue<int> del;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) mp[i].clear();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		mp[u][v] = 1;
		mp[v][u] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		s.insert(i);
	}
	ans.clear();
	while (!s.empty()) {
		int u = *(s.begin());
		s.erase(u);
		int res = 1;
		while (!q.empty()) q.pop();
		q.push(u);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			while (!del.empty()) del.pop();
			for (auto &y : s) {
				if (mp[x][y] == 0) {
					q.push(y);
					del.push(y);
					res++;
				}
			}
			while (!del.empty()) {
				int y = del.front();
				del.pop();
				s.erase(y);
			}
		}
		ans.push_back(res);
	}
	sort(ans.begin(), ans.end());
	int len = ans.size();
	cout << len << '\n';
	for (int i = 0; i < len; ++i) {
		cout << ans[i];
		if (i == len - 1) cout << '\n';
		else cout << ' ';
	}
    return 0;
}

