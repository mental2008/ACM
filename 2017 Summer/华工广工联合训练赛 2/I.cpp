#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1100
using namespace std;
//const int upper = 356;
int ans[maxn], sum, temp[maxn];

void dfs(int n, int upper, int now) {
	if(n == 0) {
		if(now - 1 < sum) {
			for(int i = 1; i < now; i++) {
				ans[i] = temp[i];
				sum = now - 1;
			}
		}
		return;
	}
	if(now >= sum) return;
	for(int i = upper; i >= 1; i--) {
		if(n < i * i * i) continue;
		if(n / (i * i * i) + now > sum) return;
		temp[now] = i;
		dfs(n - i * i * i, i, now + 1);
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		sum = 0x3f3f3f3f;
		memset(ans, 0, sizeof(ans));
		memset(temp, 0, sizeof(temp));
		dfs(n, 356, 1);
		printf("%d\n%d", sum, ans[1]);
		for(int i = 2; i <= sum; i++) printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
} 
