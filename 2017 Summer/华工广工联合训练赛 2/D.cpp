#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int k, pos;
	while(~scanf("%d%d", &k, &pos)) {
//		getchar();
		string s;
		cin >> s;
		for(int i = 0; i < k; i++) {
			string temp = "";
			for(int j = 0; j < s.size(); j += 2) {
				for(int l = 0; l < (s[j] - '0'); l++) {
					temp += s[j + 1];
				}
			}
			s = temp;
		}
		int ans = s[pos] - '0';
		printf("%d\n", ans);
	}
	return 0;
} 
