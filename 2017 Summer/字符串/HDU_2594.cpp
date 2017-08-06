#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50005;
char s1[maxn];
char s2[maxn];
int nxt[maxn];

void getNext(char *ch) {
	int len = strlen(ch);
	nxt[0] = 0, nxt[1] = 0;
	for(int i = 1; i < len; i++) {
		int j = nxt[i];
		while(j && ch[i] != ch[j]) j = nxt[j];
		nxt[i + 1] = ch[i] == ch[j] ? j + 1 : 0;
	}
//	int i = 0, j = -1;
//	nxt[0] = -1;
//	while(i < len) {
//		if(j < 0 || ch[i] == ch[j]) {
//			++i, ++j;
//			if(ch[i] == ch[j]) nxt[i] = nxt[j];
//			else nxt[i] = j;
//		}
//		else j = nxt[j];
//	}
}

int kmp(char *s, char *t) {
	int lens = strlen(s);
	int lent = strlen(t);
	getNext(t);
	int j = 0;
	for(int i = 0; i < lens; i++) {
		while(j && s[i] != t[j]) j = nxt[j];
		if(s[i] == t[j]) j++;
	}
//	int i = 0, j = 0;
//	while(i < lens) {
//		if(j < 0 || s[i] == t[j]) {
//			++i, ++j;
//		}
//		else j = nxt[j];
//	}
	return j;
}

int main() {
	while(~scanf("%s", s1)) {
		scanf("%s", s2);
		int ans = kmp(s2, s1);
		for(int i = 0; i < ans; i++) {
			printf("%c", s1[i]);
		}
		if(ans) printf(" ");
		printf("%d\n", ans);
	}
	return 0;
}
