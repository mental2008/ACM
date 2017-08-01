#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
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
	while(~scanf("%s", s)) {
		if(!strcmp(s, ".")) break;
		int len = strlen(s);
		getNext(s);
		if(len % (len - nxt[len]) != 0) puts("1");
		else printf("%d\n", len / (len - nxt[len]));
	}
	return 0;
}
