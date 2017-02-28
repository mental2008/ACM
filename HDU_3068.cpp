#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iomanip>
#define maxn 110010
#define INF 99999999
using namespace std;
char s[2 * maxn];
int p[2 * maxn];
int main(){
	while(scanf("%s", s) != EOF){
		int len = strlen(s), id = 0, maxlen = 0;
		for(int i = len; i >= 0; --i){
			s[i + i + 2] = s[i];
			s[i + i + 1] = '#';
		}
		s[0] = '*';
		for(int i = 2; i < 2 * len + 1; ++i){
			if(p[id] + id > i){
				p[i] = min(p[2 * id - i], p[id] + id - i);
			}
			else{
				p[i] = 1;
			}
			while(s[i - p[i]] == s[i + p[i]]){
				++p[i];
			}
			if(id + p[id] < i + p[i]){
				id = i;
			}
			if(maxlen < p[i]){
				maxlen = p[i];
			}
		}
		cout << maxlen - 1 << endl;
	}
	return 0;
}
