#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef unsigned long long ull;

int main() {
	__int128 res=0;
	int n;
	scanf("%d",&n);
	rep(i,1,n) {
		ll a;
		scanf("%lld",&a);
		if(a<0) res+=a*i;
		else res+=a;
	}
	ull ans=0;
	if(res>=0) ans=res;
	else ans=-res;
	if(res>=0) printf("%llu\n",ans);
	else printf("-%llu\n",ans);
	return 0;
}