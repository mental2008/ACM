#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
int a[maxn];
int b[maxn];
int nxt[maxn];

void getNext(int ch[], int len) {
	nxt[0] = 0, nxt[1] = 0;
	for(int i = 1; i < len; i++) {
		int j = nxt[i];
		while(j && ch[i] != ch[j]) j = nxt[j];
		nxt[i + 1] = ch[i] == ch[j] ? j + 1 : 0;
	}
}

int kmp(int s[], int t[], int lens, int lent) {
	getNext(t, lent);
	int count = 0;
	int j = 0;
	for(int i = 0; i < lens; i++) {
		while(j && s[i] != t[j]) j = nxt[j];
		if(s[i] == t[j]) j++;
		if(j == lent) {
			return (i - lent + 2);
		}
	}
	return -1;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < m; i++) scanf("%d", &b[i]);
		int ans = kmp(a, b, n, m);
		printf("%d\n", ans);
	}
	return 0;
}
