#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
map<char, int> mp;
char pattern[maxn];
char temp[maxn];
char good[30]; 
int n;
int pos;

bool judge() {
	if(pos == -1) {
		if(strlen(pattern) != strlen(temp)) return false;
		for(int i = 0; i < strlen(pattern); i++) {
			if(pattern[i] == '?') {
				if(!mp[temp[i]]) return false;
			}
			else if(pattern[i] != temp[i]) return false;
		}
		return true;
	}
	else {
		int len = strlen(temp) - strlen(pattern);
		if(len <= -2) return false;
		for(int i = 0; i < pos; i++) {
			if(pattern[i] == '?') {
				if(!mp[temp[i]]) return false;
			}
			else if(pattern[i] != temp[i]) return false;
		}
		if(len != -1) {
			for(int i = pos; i <= len + pos; i++) {
				if(mp[temp[i]]) return false;
			}
		}
		for(int i = pos + 1; i < strlen(pattern); i++) {
			if(pattern[i] == '?') {
				if(!mp[temp[i + len]]) return false;
			}
			else if(pattern[i] != temp[i + len]) return false;
		}
		return true;
	}
}

int main() {
	mp.clear();
	scanf("%s", good);
	for(int i = 0; i < strlen(good); i++) {
		mp[good[i]] = 1;
	}
	scanf("%s", pattern);
	pos = -1;
	for(int i = 0; i < strlen(pattern); i++) {
		if(pattern[i] == '*') {
			pos = i;
			break;
		}
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", temp);
		if(judge()) puts("YES");
		else puts("NO"); 
	}
	return 0;
}
