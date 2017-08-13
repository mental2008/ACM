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
int p;
int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d", &p);
		p--;
		int sum = 0;
		for(int i = 1; i * i <= p; i++) {
			if(p % i == 0) {
				if(i * i == p) sum++;
				else sum += 2;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
