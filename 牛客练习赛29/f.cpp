#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=2e6+5;
int n,m;
ll cnt[maxn];
ll sum[maxn];
ll pre[maxn];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		int val;
		scanf("%d",&val);
		cnt[val]++;
	}
	sum[0]=0;
	rep(i,1,m) sum[i]=sum[i-1]+cnt[i];
	rep(i,1,m) {
		for(int j=i;j<=m;j+=i) {
			pre[j]+=cnt[i];
		}
	}
	ll ans=0;
	rep(x,1,m) {
		ll res=0;
		pre[x]+=pre[x-1];
		res+=pre[x];
		for(ll k=1;;++k) {
			ll l=k*x;
			if(l>m) break;
			ll r=(k+1)*x-1;
			r=min(r,1ll*m);
			res+=(sum[r]-sum[l-1])*k;
		}
		// cout<<res<<endl;
		ans^=res;
	}
	printf("%lld\n",ans);
	return 0;
}