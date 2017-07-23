#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int INF = (1 << 30) - 1;
int n;
int value[maxn];
int cntbox, cntgoods;
int box[maxn];
int goods[maxn];
int match[maxn];
int vis_goods[maxn];
int vis_box[maxn];
int d;
int a[maxn][maxn];

bool dfs(int i) {
	vis_goods[i] = 1;
	for(int j = 1; j <= cntbox; j++) {
		if(vis_box[j]) continue;
		int gap = goods[i] + box[j] - a[i][j];
		if(gap == 0) {
			vis_box[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
		else d = min(d, gap);
	}
	return false;
}

void KM() {
	memset(match, -1, sizeof(match));
	memset(box, 0, sizeof(box));
	for(int i = 1; i <= cntgoods; i++) {
		goods[i] = -INF;
		for(int j = 1; j <= cntbox; j++) {
			goods[i] = max(goods[i], a[i][j]);
		}
	}
	for(int i = 1; i <= cntgoods; i++) {
		while(1) {
			memset(vis_goods, 0, sizeof(vis_goods));
			memset(vis_box, 0, sizeof(vis_box));
			d = INF;
			if(dfs(i)) break;
			for(int j = 1; j <= cntgoods; j++) if(vis_goods[j]) goods[j] -= d;
			for(int j = 1; j <= cntbox; j++) if(vis_box[j]) box[j] += d;
		}
	}
	int ans = 0;
	for(int i = 1; i <= cntbox; i++) {
		if(match[i] != -1) ans -= a[match[i]][i];
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d", &n)) {
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &value[i]);
			sum += value[i];
		}
		cntbox = 0, cntgoods = 0;
		int average = sum / n;
		for(int i = 1; i <= n; i++) {
			if(value[i] < average) {
				while(value[i] < average) {
					box[++cntbox] = i;
					value[i]++;
				}
			}
			else if(value[i] > average) {
				while(value[i] > average) {
					goods[++cntgoods] = i;
					value[i]--;
				}
			}
		}
		for(int i = 1; i <= cntgoods; i++) {
			for(int j = 1; j <= cntbox; j++) {
				a[i][j] = -min(abs(goods[i] - box[j]), n - abs(goods[i] - box[j]));
			}
		}
		KM();
	}
	return 0;
}
