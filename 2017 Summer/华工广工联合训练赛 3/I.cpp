#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int n;
struct node {
	int num;
	bool sign;
}a[maxn];
int main() {
//	freopen("in.txt", "r", stdin);
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d", &n);
		int w = 0, b = 0;
		for(int i = 1; i <= n; i++) {
			int k;
			char ch;
			scanf("%d %c", &k, &ch);
			a[i].num = k;
			if(ch == 'B') a[i].sign = true, b += k;
			else a[i].sign = false, w += k;
		}
		if(b == 0) printf("%d\n", w);
		else if(w == 0) printf("%d\n", b);
		else {
			int tempw = 0, tempb = 0;
			int ans = 0;
			for(int i = 1; i <= n; i++) {
//				printf("tempw = %d tempb = %d\n", tempw, tempb);
				if(tempw == 0 && tempb == 0) {
					if(a[i].sign) tempb += a[i].num;
					else tempw += a[i].num;
					continue;
				}
				if(1LL * b * tempw < 1LL * w * tempb) {
					if(a[i].sign) tempb += a[i].num;
					else {
						if((1LL * w * tempb) % b == 0) {
							int x = (1LL * w * tempb) / b - tempw;
							if(x <= a[i].num) {
								ans++;
								tempb = 0;
								tempw = a[i].num - x;								
							}
							else tempw += a[i].num;
						}
						else tempw += a[i].num;
					}
				}
				else if(1LL * b * tempw > 1LL * w * tempb) {
					if(!a[i].sign) tempw += a[i].num;
					else {
						if((1LL * b * tempw) % w == 0) {
							int x = (1LL * b * tempw) / w - tempb;
							if(x <= a[i].num) {
								ans++;
								tempw = 0;
								tempb = a[i].num - x;								
							}
							else tempb += a[i].num;
						}
						else tempb += a[i].num;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
