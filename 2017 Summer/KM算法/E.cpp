#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int INF = (1 << 30) - 1;
int n;
int cntfood, cntbox;
int food[maxn], box[maxn];
int a[maxn][maxn];
int match[maxn];
bool vis_food[maxn];
bool vis_box[maxn];
int slack[maxn];

bool dfs(int i) {
	vis_food[i] = 1;
	for(int j = 1; j <= cntbox; j++) {
		if(vis_box[j]) continue;
		int gap = food[i] + box[j] - a[i][j];
		if(gap == 0) {
			vis_box[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
		else slack[j] = min(slack[j], gap);
	}
	return false;
}

void KM() {
	memset(match, -1, sizeof(match));
	memset(box, 0, sizeof(box));
	for(int i = 1; i <= cntfood; i++) {
		food[i] = a[i][1];
		for(int j = 2; j <= cntbox; j++) {
			food[i] = max(food[i], a[i][j]);
		}
	}
	for(int i = 1; i <= cntfood; i++) {
		for(int j = 1; j <= cntbox; j++) slack[j] = INF;
		while(1) {
			memset(vis_food, 0, sizeof(vis_food));
			memset(vis_box, 0, sizeof(vis_box));
			if(dfs(i)) break;
			int d = INF;
			for(int j = 1; j <= cntbox; j++) {
				if(!vis_box[j]) d = min(d, slack[j]);
			}
			for(int j = 1; j <= cntfood; j++) if(vis_food[j]) food[j] -= d;
			for(int j = 1; j <= cntbox; j++) {
				if(vis_box[j]) box[j] += d;
				else slack[j] -= d;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cntbox; i++) {
		if(match[i] != -1) {
			ans -= a[match[i]][i];
		}
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d", &n)) {
		cntfood = 0, cntbox = 0;
		memset(food, 0, sizeof(food));
		memset(box, 0, sizeof(box));
		for(int i = 1; i <= n; i++) {
			int value;
			scanf("%d", &value);
			if(value >= 2) {
				while(value > 1) {
					food[++cntfood] = i;
					value--;
				}
			}
			else if(value == 0){
				box[++cntbox] = i;
			}
		}
		for(int i = 1; i <= cntfood; i++) {
			for(int j = 1; j <= cntbox; j++) {
				a[i][j] = (-1) * min(abs(food[i] - box[j]), n - abs(food[i] - box[j]) );
			}
		}
		KM();
	}
	return 0;
} 
