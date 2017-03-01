#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define maxn 1000000 + 10
using namespace std;
char s[2 * maxn];
int p[2 * maxn];
int main(){
	int num = 0;
	string tmp;
	while(cin >> tmp){
		if(tmp == "END") break;
		memset(p, 0, sizeof(p));
		int len = tmp.size(), id = 0, maxlen = 0;
		for(int i = len; i >= 0; i--){
			s[2 * i + 2] = tmp[i];
			s[2 * i + 1] = '#';
		}
		s[0] = '*';
		for(int i = 2; i <= 2 * len + 1; i++){
			if(p[id] + id > i) p[i] = min(p[2 * id - i], p[id] + id - i);
			else p[i] = 1;
			while(s[i - p[i]] == s[i + p[i]]) p[i]++;
			if(p[i] + i > p[id] + id) id = i;
			maxlen = max(maxlen, p[i]);
		}
		num++;
		printf("Case %d: %d\n", num, maxlen - 1);
	}
	return 0;
}
