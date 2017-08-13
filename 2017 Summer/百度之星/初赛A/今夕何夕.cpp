#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int year, month, day;

int cal(int y, int m, int d) {
	if(m == 1 || m == 2) {
		m += 12;
		y--;
	}
	int c = y / 100;
	y = y - c * 100;
	int ans = ((y + (y / 4) + (c / 4) - 2 * c + ((26 * (m + 1)) / 10) + d - 1) % 7 + 7) % 7;
	while(ans < 0) {
		ans += 7;
	}
	ans %= 7;
	return ans;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d-%d-%d", &year, &month, &day);
		int start = cal(year, month, day);
		for(int i = year + 1; i <= 9999 ; i++) {
			if(month == 2 && day == 29) {
				if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
					;
				}
				else continue;
			} 
			int end = cal(i, month, day);
			if(end == start) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
