#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1005;
int n;
ll b[maxn];

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&b[i]);
	sort(b+1,b+1+n);
	ll ans=0;
	ll pre=0;
	for(int i=1;i<=n;++i) {
		pre+=b[i];
		ans+=pre;
	}
	printf("%lld\n",ans);
	return 0;
}