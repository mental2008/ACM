#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;
int n;
int fuck[2 * maxn];
vector<int> vec;

void init() {
	for(int i = 1; i <= 2 * n; i++) fuck[i] = i;
}

int find(int x) {
	return (fuck[x] == x ? x : fuck[x] = find(fuck[x]));
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		vec.clear();
		int sum = 0;
		int num = 0;
		for(int i = 1; i <= n; i++) {
			num++;
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			int fa_u1 = find(u);
			int fa_u2 = find(u + n);
			int fa_v1 = find(v);
			int fa_v2 = find(v + n);
			if(w == 1) {
				if(fa_u1 == fa_v2 || fa_v1 == fa_u2) {
					sum++;
					init();
					vec.push_back(num);
					num = 0;
				}
				else {
					fuck[fa_u1] = fa_v1;
				}
			}
			else {
				if(fa_u1 == fa_v1) {
					sum++;
					init();
					vec.push_back(num);
					num = 0;
				}
				else {
					fuck[fa_u1] = fa_v2;
					fuck[fa_v1] = fa_u2;
				}
			}
		}
		if(num) {
			sum++;
			//vec.push_back(num);
		} 
		printf("%d\n", sum);
		for(int i = 0; i < vec.size(); i++) {
			printf("%d", vec[i]);
			if(i != vec.size() - 1) printf(" ");
		}
		if((int)vec.size()) puts("");
	}
	return 0;
}
