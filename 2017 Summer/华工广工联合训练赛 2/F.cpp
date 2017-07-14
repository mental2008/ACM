#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL num[10];
int main() {
    for(int i = 1; i < 10; i++) {
		num[i] = (1LL * i * pow(26, i));
	}
	int n;
	int ch[10];
	while(~scanf("%d", &n)) {
		memset(ch, 0, sizeof(ch));	
		for(int len = 1; len < 10; len++) {
			if(n >= num[len]) n -= num[len];
			else {
				int index = n / len;
				for(int i = len - 1; index; i--) {
					ch[i] = index % 26;
					index /= 26;
				}
				printf("%c\n", (char(ch[n % len] + 'A')));
				break;
			}
		}
	}
	return 0;
}
