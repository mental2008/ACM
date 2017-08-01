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

int main() {
	while(~scanf("%s", s)) {
		getNext(s);
		for(int i = 0; i <= strlen(s); i++) {
			printf("%d ", nxt[i]);
		}
		puts("");
		//printf("%d\n", strlen(s) - nxt[strlen(s)]);
	}
	return 0;
}
