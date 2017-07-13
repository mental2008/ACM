#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define LL long long
#define maxn 50100
using namespace std;
int g, w;
int a[maxn], b[maxn];
priority_queue<int, vector<int>, greater<int> > que; 

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	int num = 0;
	while(caseCnt--) {
		memset(a, 0, sizeof(a));
		num++;
		printf("Case %d:\n", num);
		scanf("%d%d", &g, &w);
		for(int i = 1; i <= g; ++i) {
			scanf("%d",&a[i]);
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			while(!que.empty()) que.pop();
			for(int i = 1; i <= w; i++) que.push(0);
			int index, update;
			scanf("%d%d", &index, &update);
			a[index] = update;
			for(int i = 1; i <= g; i++) {
				b[i] = a[i];
			}
			sort(b + 1, b + g + 1, cmp);
			LL ans = 0;
			for(int i = 1; i <= g; i++) {
//				ans += b[i] + que.top();
//				int temp = que.top();
//				que.pop();
//				que.push(b[i] + temp);
				ans += b[i] * ((i + w - 1) / w);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
} 
