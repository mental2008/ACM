#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define maxn 1000000 + 10
using namespace std;
int p[2 * maxn];
char s[2 * maxn];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		memset(p, 0, sizeof(p));
		int len = strlen(s), id = 0, maxlen = 0;
		for(int i = len; i >= 0; i--){
			s[2 * i + 2] = s[i];
			s[2 * i + 1] = '#';
		}
		s[0] = '*';
		for(int i = 2; i <= 2 * len + 1; i++){
			if(id + p[id] > i){
				p[i] = min(p[2 * id - i], p[id] + id - i);
			}
			else{
				p[i] = 1;
			}
			while(s[i - p[i]] == s[i + p[i]]){
				p[i]++;
			}
			if(p[i] + i > p[id] + id){
				id = i;
			}
			if(p[i] > maxlen){
				maxlen = p[i];
			}
		}
		printf("%d\n", maxlen - 1);
	}
	return 0;
}
