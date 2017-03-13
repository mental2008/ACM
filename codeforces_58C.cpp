#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100000 + 10
using namespace std;
int a[maxn];
int sum[maxn];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		int mid = (1 + n) / 2;
		for(int i = 1; i <= mid; i++){
			if(a[i] - i + 1 > 0){
				sum[a[i] - i + 1]++;
			}
		}
		for(int i = n; i > mid; i--){
			if(a[i] + i - n > 0){
				sum[a[i] + i - n]++;
			}
		}
		int ans = -1;
		for(int i = 1; i <= maxn; i++){
			ans = max(sum[i], ans);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
