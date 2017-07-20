#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
const int a[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 0, -1};

void dfs(int num, int count, int x, int y) {
	bool is_ok = true;
	if(num >= 250) return;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] == num) {
			is_ok = false;
			break;
		}
	}
	if(is_ok) vec.push_back(num);
	if(count >= 3) return;
	for(int i = x; i < 4; i++) {
		for(int j = y; j < 3; j++) {
			if(a[i][j] != -1) {
				dfs(num * 10 + a[i][j], count + 1, i, j);
			}
		}
	}
}

void init() {
	vec.clear();
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			if(a[i][j] != -1) dfs(a[i][j], 1, i, j);
		}
	}
	sort(vec.begin(), vec.end());
//	for(int i = 0; i < vec.size(); i++) {
//		printf("%d\n", vec[i]);
//	}
}

int main() {
	init();
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		int k;
		scanf("%d", &k);
		int sum = abs(k - vec[0]);
		int ans = vec[0];
		for(int i = 1; i < vec.size(); i++) {
			if(sum > abs(k - vec[i])) {
				sum = abs(k - vec[i]);
				ans = vec[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
