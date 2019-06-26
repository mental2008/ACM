#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x,ll y) {
	return y==0?x:gcd(y,x%y);
}
ll lcm(ll x,ll y) {
	return x/gcd(x,y)*y;
}
ll a,b;
ll k,p;
void solve(ll m) {
	ll t=a/m+1;
	ll x=t*m-a;
	ll res=lcm(a+x,b+x);
	if(res<p) {
		p=res;
		k=x;
	}
	else if(res==p) k=min(k,x);
}

int main() {
	scanf("%lld%lld",&a,&b);
	if(a>b) swap(a,b);
	if(b%a==0) return 0*puts("0");
	ll x=b-a;
	k=0;
	p=lcm(a,b);
	for(ll i=1;i*i<=x;++i) {
		if(x%i==0) {
			solve(i);
			solve(x/i);
		}
	}
	printf("%lld\n",k);
	return 0;
}