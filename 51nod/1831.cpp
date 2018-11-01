#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int caseCnt;
	scanf("%d",&caseCnt);
	while(caseCnt--) {
		ll n;
		scanf("%lld",&n);
		bool prime=1;
		for(ll i=2;i*i<=n;++i) {
			if(n%i==0) {
				prime=0;
				break;
			}
		}
		if(prime&&n!=2&&n!=17) puts("NIE");
		else {
			if(n==16||n==34||n==289) puts("NIE");
			else puts("TAK");
		}
	}
	return 0;
}