#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int op[maxn][maxn];
int vis[200000];
int res[20000];

void init() {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			scanf("%d", &op[i][j]);
		}
	}
	memset(vis, 0, sizeof(vis));
	memset(res, 0, sizeof(res));
}

int createNum(int a, int b, int c, int d) {
	a = op[0][a];
	b = op[a][b];
	c = op[b][c];
	d = op[c][d];
	return d;
}

void dfs(int now) {
	int bit[10];
	memset(bit, 0, sizeof(bit));
	int temp = now, num = 4;
	while(num >= 0) {
		bit[num] = temp % 10;
		temp /= 10;
		num--;
	}
	for(int i = 0; i < 5; i++) {
		int x = 0;
		for(int j = 0; j < i; j++) x = x * 10 + bit[j];
		for(int k = 0; k < 10; k++) {
			int xx = x * 10 + k;
			for(int t = i + 1; t < 5; t++) xx = xx * 10 + bit[t];
			if(xx >= 100000) continue;
			if(vis[xx] && xx != now) {
				return;
			}
		}
	}
	for(int i = 0; i < 4; i++) {
		int tempbit[10];
		for(int j = 0; j < 5; j++) {
			tempbit[j] = bit[j];
		}
		int tem = tempbit[i + 1];
		tempbit[i + 1] = tempbit[i];
		tempbit[i] = tem;
		int x = 0;
		for(int j = 0; j < 5; j++) {
			x = tempbit[j] + x * 10;
		}
		if(x >= 100000) continue;
		if(vis[x] && x != now) return;
	}
	res[now / 10] = 1;
}

void solve() {
	for(int i = 0; i < 10000; i++) {
		int bit[10];
		memset(bit, 0, sizeof(bit));
		int num = 3, temp = i;
		while(num >= 0) {
			bit[num] = temp % 10;
			temp /= 10;
			num--;
		}
		int result = createNum(bit[0], bit[1], bit[2], bit[3]);
		for(int j = 0; j < 10; j++) {
			if(op[result][j] == 0) {
				int x = i * 10 + j;
				vis[x] = 1;
			}
		}
		result = i * 10 + result;
		vis[result] = 1;
//		printf("%d\n", result);
	}
	for(int i = 0; i < 100000; i++) {
		if(vis[i]) dfs(i);
	}
	int ans = 0;
	for(int i = 0; i < 10000; i++) {
		if(res[i]) {
			ans++;
		}
	}
	printf("%d\n", 10000 - ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	init();
	solve();
	return 0;
}
