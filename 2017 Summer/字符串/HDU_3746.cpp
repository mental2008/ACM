#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
char s[maxn];
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

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%s", s);
		getNext(s);
		int len = strlen(s);
		int cycle = len - nxt[len];
		if(len % cycle == 0 && len / cycle > 1) puts("0");
		else if(len % cycle == 0) printf("%d\n", cycle);
		else printf("%d\n", cycle - len % cycle);
	}
	return 0;
}
