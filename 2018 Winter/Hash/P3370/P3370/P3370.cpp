// P3370.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1000007;
struct Node {
	int nxt;
	string s;
} node[maxn];
int n;
int cnt;
int head[maxn];

bool Hash(string s) {
	int len = s.size();
	int res = 0;
	for (int i = 0; i < len; ++i) {
		res = (res * 37 + s[i] - 48) % maxn;
	}
	for (int i = head[res]; i != -1; i = node[i].nxt) {
		if (node[i].s == s) {
			return false;
		}
	}
	node[cnt].s = s;
	node[cnt].nxt = head[res];
	head[res] = cnt++;
	return true;

}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		string s;
		cnt = 0;
		int ans = 0;
		memset(head, -1, sizeof(head));
		while (n--) {
			cin >> s;
			if (Hash(s)) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
    return 0;
}

