#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxt = 1000005;
const int maxw = 10005;
char w[maxw];
char t[maxt];
int nxt[maxw];

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

int kmp() {
	int lenw = strlen(w), lent = strlen(t);
	int i = 0, j = 0;
	int count = 0;
	while(i < lent) {
		if(j < 0 || t[i] == w[j]) {
			++i, ++j;
		}
		else j = nxt[j];
		if(j == lenw) {
			count++;
			j = nxt[j];
		}
	}
	return count;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	getchar();
	while(caseCnt--) {
		scanf("%s", w);
		scanf("%s", t);
		getNext(w);
		int ans = kmp();
		printf("%d\n", ans);
	}
	return 0;
}
