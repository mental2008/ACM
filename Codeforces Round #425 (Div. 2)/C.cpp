#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n, s;
int x[maxn];
int v[maxn];
int t[maxn];
int lower, upper;

double cal(int ray) {
	double ans = 0;
	for(int i = 1; i <= n; i++) {
		double res = 0;
		if(ray == x[i]) {
			int tempv = v[i] + s;
			if(t[i] == 1) {
				res = (double)(x[i] - lower) / tempv;
			}
			else {
				res = (double)(upper - x[i]) / tempv;
			}
		}
		else if(ray > x[i]) {
			if(t[i] == 1) {
				if(1LL * v[i] * (ray - x[i]) >= 1LL * x[i] * (s - v[i])) {
					res = (double)(x[i] - lower) / v[i];
				}
				else {
					double tempt = (double)(ray - x[i]) / (s - v[i]);
					double temps = v[i] * tempt;
					res = tempt + (double)(x[i] - temps) / (v[i] + s);
				}
			}
			else {
				res = (double)(upper - x[i]) / v[i];
			}
		}
		else {
			if(t[i] == 2) {
				if(1LL * v[i] * (x[i] - ray) >= 1LL * (upper - x[i]) * (s - v[i])) {
					res = (double)(upper - x[i]) / v[i];
				}
				else {
					double tempt = (double)(x[i] - ray) / (s - v[i]);
					double temps = v[i] * tempt;
					res = tempt + (double)(upper - x[i] - temps) / (v[i] + s);
				}
			}
			else {
				res = (double)x[i] / v[i];
			}
		}
//		printf("res = %lf\n", res);
		ans = max(res, ans);
	}
	return ans;
}

int main() {
	lower = 0, upper = 1e6;
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x[i], &v[i], &t[i]);
	}
	int l = 0, r = 1e6;
	double leftans = cal(l), rightans = cal(r);
	double ans = min(leftans, rightans);
	while(l < r) {
		int mid = (l + r) / 2;
		leftans = cal(l);
		rightans = cal(r);
		double midans = cal(mid);
		if(leftans < rightans) {
			r = mid - 1;
			ans = min(leftans, ans);
		}
		else {
			l = mid + 1;
			ans = min(rightans, ans);
		}
		ans = min(midans, ans);
	}
	printf("%.6lf\n", ans);
	return 0;
}
