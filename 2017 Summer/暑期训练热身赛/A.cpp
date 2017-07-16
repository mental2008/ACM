#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;

struct node {
	int value, index;
}a[maxn];

void init(int n) {
	for(int i = 1; i <= n; i++) {
		a[i].value = i;
		a[i].index = i;
	}
}

bool cmp(node x, node y) {
	return x.value < y.value;
}

int main() {
	int n, m; 
	while(~scanf("%d%d", &n, &m)) {
		init(n);
		int num = 0;
		for(int i = 1; i <= m; i++) {
			int temp;
			scanf("%d", &temp);
			a[temp].value = num;
			num--;
		}
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1; i <= n; i++) {
			printf("%d\n", a[i].index);
		}
	}
	return 0;
}
