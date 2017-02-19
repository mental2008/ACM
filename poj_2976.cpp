#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
#define LL long long
using namespace std;
LL a[maxn+5], b[maxn+5];
int n, k;

bool cmp(LL x, LL y){
	return x > y;
}

bool check(double ans){
	double sum[maxn+5];
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i++){
		sum[i] = 100 * a[i] - ans * b[i];
	}
	sort(sum + 1, sum + n + 1, cmp);
	double res = 0;
	for(int i = 1; i <= (n - k); i++){
		res += sum[i];
	}
	return res >= 0;
}

int f(double ans){
	int res = ans;
	if(ans - res > res + 1 - ans) return res + 1;
	return res;
}

int main(){
	while(scanf("%d%d", &n, &k)){
		if(n == 0 && k == 0) break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		for(int i = 1; i <= n; i++){
			scanf("%lld", &b[i]);
		}
		double l = 0, r = 100, mid;
		while(r - l > 0.0001){
			mid = (l + r) / 2;
			if(check(mid)) l = mid;
			else r = mid;
		}
		printf("%d\n", f(mid));
	}
	return 0;
}
