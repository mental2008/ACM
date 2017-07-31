#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 16000005;
int hash0[maxn];
int n, m;
int value[300];
char s[maxn];
int main() {
	while(~scanf("%d%d", &n, &m)) {
		scanf("%s", s);
		int cnt = 0;
		memset(value, -1, sizeof(value));
		memset(hash0, 0, sizeof(hash0));
		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			if(value[s[i]] == -1) {
				value[s[i]] = cnt++;
			}
		}
		int ans = 1;
		int res = 0;
		int temp = 1;
		for(int i = 0; i < n; i++) {
			res = res * m + value[s[i]];
			temp *= m;
		}
		hash0[res] = 1;
		temp /= m;
		for(int i = 1; i <= len - n; i++) {
			res = (res - (value[s[i - 1]] * temp)) * m + value[s[i + n - 1]];
			if(!hash0[res]) {
				ans++;
				hash0[res] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
