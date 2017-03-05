#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000
using namespace std;
char s[maxn + 5];
char t[maxn + 5];
int nxt[maxn + 5];

void getNext(char *ch){
	int len = strlen(ch);
	int i = 0, j = -1;
	nxt[0] = -1;
	while(i < len){
		if(j < 0 || ch[i] == ch[j]){
			++i, ++j;
			if(ch[i] == ch[j]) nxt[i] = nxt[j];
			else nxt[i] = j;
		}
		else j = nxt[j];
	}
}

int kmp(){
	int tlen = strlen(t), slen = strlen(s);
	int i = 0, j = 0;
	int count = 0;
	while(i < tlen){
		if(j < 0 || t[i] == s[j]){
			++i, ++j;
		}
		else j = nxt[j];
		if(j == slen){
			count++;
			j = nxt[j];
		}
	}
	return count;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		scanf("%s" , t);
		getNext(s);
		printf("%d\n", kmp());
	}
	return 0;
}
