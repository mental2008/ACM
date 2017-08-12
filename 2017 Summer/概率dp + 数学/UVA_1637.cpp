#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
double dp[5][5][5][5][5][5][5][5][5];
bool vis[5][5][5][5][5][5][5][5][5];
string s[9][4];

double dfs(int w1, int w2, int w3, int w4, int w5, int w6, int w7, int w8, int w9) {
	if(vis[w1][w2][w3][w4][w5][w6][w7][w8][w9]) {
		return dp[w1][w2][w3][w4][w5][w6][w7][w8][w9];
	}
	vis[w1][w2][w3][w4][w5][w6][w7][w8][w9] = 1;
	int top[10] = {w1, w2, w3, w4, w5, w6, w7, w8, w9};
	int sum = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = i + 1; j < 9; j++) {
			if(top[i] == 0 || top[j] == 0) continue;
			if(s[i][top[i] - 1][0] == s[j][top[j] - 1][0]) {
				sum++;
			}
		}
	}
	double P = 1.0 / sum;
	dp[w1][w2][w3][w4][w5][w6][w7][w8][w9] = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = i + 1; j < 9; j++) {
			if(top[i] == 0 || top[j] == 0) continue;
			if(s[i][top[i] - 1][0] == s[j][top[j] - 1][0]) {
				top[i]--, top[j]--;
				dp[w1][w2][w3][w4][w5][w6][w7][w8][w9] += (P * dfs(top[0], top[1], top[2], top[3], top[4], top[5], top[6], top[7], top[8]));
				top[i]++, top[j]++;
			}
		}
	}
	return dp[w1][w2][w3][w4][w5][w6][w7][w8][w9];
}

int main() {
	ios::sync_with_stdio(false);
	while(cin >> s[0][0]) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 4; j++) {
				if(i == 0 && j == 0) continue;
				cin >> s[i][j];
			}
		}
		mem(vis, 0);
		vis[0][0][0][0][0][0][0][0][0] = 1;
		dp[0][0][0][0][0][0][0][0][0] = 1;
		double ans = dfs(4, 4, 4, 4, 4, 4, 4, 4, 4);
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
