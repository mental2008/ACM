#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =  1000005;
int n;
char s[maxn];
int nxt[maxn];

void getNext(char *ch) {
	int len = strlen(ch);
	for(int i = 1; i < len; i++) {
		int j = nxt[i];
		while(j && ch[i] != ch[j]) j = nxt[j];
		nxt[i + 1] = ch[i] == ch[j] ? j + 1 : 0;
	}
}

int main() {
	int caseCnt = 0;
	while(~scanf("%d", &n), n) {
		caseCnt++;
		scanf("%s", s);
		getNext(s);
		printf("Test case #%d\n", caseCnt);
		for(int i = 2; i <= n; i++) {
			if(nxt[i] > 0 && i % (i - nxt[i]) == 0) {
				printf("%d %d\n", i, i / (i - nxt[i]));
			}
		}
		puts("");
	}
	return 0;
} 
