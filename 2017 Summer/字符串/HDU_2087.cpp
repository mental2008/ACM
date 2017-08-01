#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
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
}

int kmp(char *s, char *t) {
	int lens = strlen(s), lent = strlen(t);
	getNext(t);
	int count = 0;
	int j = 0;
	for(int i = 0; i < lens; i++) {
		while(j && s[i] != t[j]) j = nxt[j];
		if(s[i] == t[j]) j++;
		if(j == lent) {
			count++;
			j = 0;
		}
	}
	return count;
}

int main() {
	while(~scanf("%s", s1)) {
		if(!strcmp(s1, "#")) break;
		scanf("%s", s2);
		int ans = kmp(s1, s2);
		printf("%d\n", ans);
	}
	return 0;
}
