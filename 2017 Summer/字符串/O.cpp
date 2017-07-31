#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
char s1[maxn];
char s2[maxn];
int nxt[maxn];

void getNext(char *ch) {
	int len = strlen(ch);
	int i = 0, j = -1;
	nxt[0] = -1;
	while(i < len) {
		if(j < 0 || ch[i] == ch[j]) {
			++i, ++j;
			if(ch[i] == ch[j]) nxt[i] = nxt[j];
			else nxt[i] = j;
		}
		else j = nxt[j];
	}
}

int kmp(char *s, char *t) {
	int lens = strlen(s);
	int lent = strlen(t);
	getNext(t);
	int i = 0, j = 0;
	while(i < lens) {
		if(j < 0 || s[i] == t[j]) {
			++i, ++j;
		}
		else j = nxt[j];
		if(j == lent) return j;
	}
	return j;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	getchar();
	while(caseCnt--) {
		scanf("%s", s1);
		scanf("%s", s2);
		int len1 = strlen(s1), len2 = strlen(s2);
		int l1 = kmp(s1, s2);
		int l2 = kmp(s2, s1);
		if(l1 == len2) printf("%d\n", len1);
		else if(l2 == len1) printf("%d\n", len2);
		else printf("%d\n", strlen(s1) + strlen(s2) - max(l1, l2));
	}
	return 0;
}
