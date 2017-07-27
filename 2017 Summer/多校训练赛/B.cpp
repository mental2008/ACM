#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 100010;
const int MOD = 1e9 + 7;
int maxL;
int n;
struct balala {
	int value[maxn];
	int sign;
	int res;
	void init() {
		memset(value, 0, sizeof(value));
		res = -1;
	}
	bool operator < (const balala &e) const {
		for(int i = maxL - 1; i >= 0; i--) {
			if(value[i] != e.value[i]) {
				return value[i] < e.value[i];
			}
		}
		return false;
	}
} ch[30];
int front[30];
char s[maxn];
int main() {
	int caseCnt = 0;
//	freopen("1002.in", "r", stdin);
//	freopen("fuck.in", "r", stdin);
	while(~scanf("%d", &n)) {
		caseCnt++;
		memset(front, 0, sizeof(front));
		for(int i = 0; i < 26; i++) {
			ch[i].init();
			ch[i].sign = i;
		}
		maxL = -1;
		for(int i = 1; i <= n; i++) {
			scanf("%s", s);
			int len = strlen(s);
			if(len != 1) front[s[0] - 'a'] = 1;
			for(int j = 0; j < len; j++) {
				ch[s[j] - 'a'].value[len - 1 - j]++;
			}
			maxL = max(maxL, len);
		}
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < maxL; j++) {
				if(ch[i].value[j] >= 26) {
					int temp = ch[i].value[j] / 26;
					ch[i].value[j + 1] += temp;
					ch[i].value[j] %= 26;
				}
			}
			while(ch[i].value[maxL]) {
				ch[i].value[maxL + 1] += ch[i].value[maxL] / 26;
				ch[i].value[maxL++] %= 26;
			}
		}
		sort(ch, ch + 26);
		for(int i = 0; i < 26; i++) {
			ch[i].res = i;
		}
		if(front[ch[0].sign]) {
			int pos = 0;
			for(int i = 1; i < 26; i++) {
				if(!front[ch[i].sign]) {
					pos = i;
					break;
				}
			}
			ch[pos].res = 0;
			for(int i = 0; i < pos; i++) {
				ch[i].res = i + 1;
			}
		}
//		for(int i = 0; i < 26; i++) {
//			printf("%c %d\n", (ch[i].sign + 'a'), ch[i].res);
//		}
		LL ans = 0;
		for(int i = 0; i < 26; i++) {
			LL temp = 1;
			for(int j = 0; j < maxL; j++) {
				LL rest = ((temp % MOD) * (ch[i].value[j] % MOD)) % MOD;
				rest = (rest * (ch[i].res % MOD)) % MOD;
				temp = (temp * 26) % MOD;
				ans = (ans + rest) % MOD;
			}
		}
		printf("Case #%d: %lld\n", caseCnt, ans % MOD);
	}
	return 0;
} 
