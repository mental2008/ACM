// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int maxn = 30005;
string s[maxn];
int n;
vector<string> ans;
int cmp[30][30];
bool vis[30];
int child[maxn * 10][26];
bool val[maxn * 10];
int tot;

void Trie_insert(int root, string word) {
	int node = root;
	int len = word.size();
	for (int i = 0; i < len; ++i) {
		int id = word[i] - 'a';
		if (child[node][id] == 0) {
			++tot;
			memset(child[tot], 0, sizeof(child[tot]));
			child[node][id] = tot;
		}
		node = child[node][id];
	}
	val[node] = true;
}

bool Trie_check(int root, string word) {
	int node = root;
	int len = word.size();
	memset(cmp, 0, sizeof(cmp));
	for (int i = 0; i < len; ++i) {
		int id = word[i] - 'a';
		for (int j = 0; j < 26; ++j) {
			if (id == j) continue;
			if (child[node][j] == 0) continue;
			if (cmp[id][j] == -1 || cmp[j][id] == 1) return false;
			cmp[id][j] = 1;
			cmp[j][id] = -1;
		}
		node = child[node][id];
		if (i < len - 1) {
			if (val[node] == true) return false;
		}
	}
	int cnt = 26;
	memset(vis, 0, sizeof(vis));
	while (true) {
		bool ok = false;
		for (int i = 0; i < 26; ++i) {
			if (vis[i]) continue;
			bool tr = true;
			for (int j = 0; j < 26; ++j) {
				if (vis[j]) continue;
				if (i == j) continue;
				if (cmp[i][j] == -1 || cmp[j][i] == 1) {
					tr = false;
					break;
				}
			}
			if (tr) {
				vis[i] = 1;
				cnt--;
				ok = true;
				//cout << (char)(i + 'a') << '\n';
				break;
			}
		}
		if (ok && cnt == 0) return true;
		if (!ok) {
			if (cnt > 0) return false;
			else return true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		int root = 1;
		memset(child[root], 0, sizeof(child[root]));
		memset(val, false, sizeof(val));
		tot = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
			Trie_insert(root, s[i]);
		}
		ans.clear();
		for (int i = 1; i <= n; ++i) {
			if (Trie_check(root, s[i])) {
				ans.push_back(s[i]);
			}
		}
		int sz = ans.size();
		cout << sz << '\n';
		for (int i = 0; i < sz; ++i) {
			cout << ans[i] << '\n';
		}
	}
	return 0;
}
