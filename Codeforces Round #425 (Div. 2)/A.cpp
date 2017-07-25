#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k;
int main() {
	scanf("%lld%lld", &n, &k);
	LL res = n / k;
	if(res % 2 == 0) puts("NO");
	else puts("YES");
	return 0;
} 
