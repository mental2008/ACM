#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e7+5;
unordered_map<int,ull> w;
int mu[maxn];
ull sum[maxn];
int prim[maxn];
int cnt;
bool vis[maxn];
int sz;
void get_mu() {
	mu[1]=1;
	cnt=0;
	rep(i,2,maxn-1) {
		if(!vis[i]) {
			prim[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&1ll*prim[j]*i<maxn;++j) {
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
			else mu[i*prim[j]]=-mu[i];
		}
	}
	sum[0]=0;
	rep(i,1,maxn-1) sum[i]=sum[i-1]+mu[i];
}
ull djsmu(ull x) {
	if(x<maxn) return sum[x];
	if(w[x]) return w[x];
	ull ans=1;
	for(ull l=2,r;l<=x;l=r+1) {
		r=x/(x/l);
		ans-=djsmu(x/l)*(r-l+1);
	}
	return w[x]=ans;
}
ull quick_pow(ull a,ull n) {
	ull res=1;
	ull p=a;
	while(n) {
		if(n&1) res=res*p;
		p=p*p;
		n>>=1;
	}
	return res;
}

int main() {
	get_mu();
	ull n,m;
	scanf("%llu%llu",&n,&m);
	ull ans=0;
	for(ull l=1,r;l<=m;l=r+1) {
		r=m/(m/l);
		ull temp=djsmu(r)-djsmu(l-1);
		ull p=quick_pow(m/l,n);
		ans+=p*temp;
	}
	printf("%llu\n",ans);
	return 0;
}

// 632454