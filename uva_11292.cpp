#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 20100
using namespace std;
int dragon[maxn], knight[maxn];
int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m), n || m) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &dragon[i]);
		}
		for(int i = 0; i < m; i++) {
			scanf("%d", &knight[i]);
		}
		sort(dragon, dragon + n);
		sort(knight, knight + m);
		int ans = 0;
		int i, j = 0;
		for(i = 0; i < n; i++) {
			bool is_ok = false;
			while(j < m) {
				if(dragon[i] <= knight[j]) {
					is_ok = true;
					break;
				}
				j++;
			}
			if(j == m) {
				break;
			}
			if(is_ok) {
				ans += knight[j];
				j++;
			}
			
		}
		if(i == n) printf("%d\n", ans);
		else printf("Loowater is doomed!\n"); 
	}
	return 0;
} 
