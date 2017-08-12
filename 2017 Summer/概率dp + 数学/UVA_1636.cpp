#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
char s[maxn];
int main() {
	while(~scanf("%s", s)) {
		int a = 0, b = 0;
		int len = strlen(s);
		for(int i = 0; i < len; i++) {
			if(s[i] == '0') b++;
			if(i > 0 && s[i] == '0' && s[i - 1] == '0') a++;
		}
		if(s[len - 1] == '0' && s[0] == '0') a++;
		if(a * len < b * b) puts("ROTATE");
		else if(a * len > b * b) puts("SHOOT");
		else puts("EQUAL");
	}
	return 0;
}
