#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include<cmath>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}
ll extendGcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;y=0;
        return a;
    }
    ll r=extendGcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

ll ka,kb;

void solve(ll la,ll lb,ll ta,ll tb) {
    kb=0,ka=0;
    ll res=lb-la;
    if(res==0) return;
    ll d=gcd(ta,tb);
    ll k;
    ta/=d;tb/=d;
    if(res>0) {
        k=res/d;
        extendGcd(ta,tb,ka,kb);
        while(kb>0||ka<0) {
            kb-=ta;
            ka+=tb;
        }
        ka*=k;
        kb*=-k;
    }
    else {
        if((-res)%d==0) k=-res/d;
        else k=(-res/d)+1;
        extendGcd(ta,tb,ka,kb);
        while(kb<0||ka>0) {
            kb+=ta;
            ka-=tb;
        }
        ka*=-k;
        kb*=k;
    }
}
void solve2(ll la,ll lb,ll ta,ll tb) {
    kb=0,ka=0;
    ll res=la-lb;
    if(res==0) return;
    ll d=gcd(ta,tb);
    ll k;
    ta/=d;tb/=d;
    if(res>0) {
        k=res/d;
        extendGcd(ta,tb,ka,kb);
        while(kb<0||ka>0) {
            kb+=ta;
            ka-=tb;
        }
        ka*=-k;
        kb*=k;
    }
    else {
        if((-res)%d==0) k=-res/d;
        else k=(-res/d)+1;
        // cout<<k<<"\n";
        extendGcd(ta,tb,ka,kb);
        // cout<<ka<<" "<<kb<<endl;
        while(kb>0||ka<0) {
            kb-=ta;
            ka+=tb;
        }
        ka*=k;
        kb*=-k;
        // cout<<ka<<" "<<kb<<endl;
    }
}

int main() {
    ll la,ra,ta;
    ll lb,rb,tb;
    scanf("%lld%lld%lld",&la,&ra,&ta);
    scanf("%lld%lld%lld",&lb,&rb,&tb);
    ll ans=0;
    solve(la,lb,ta,tb);
    // cout<<ka<<" "<<kb<<endl;
    ll l=max(la+ka*ta,lb+kb*tb),r=min(ra+ka*ta,rb+kb*tb);
    if(l<=r) ans=max(ans,r-l+1);
    solve2(la,lb,ta,tb);
    // cout<<ka<<" "<<kb<<endl;
    l=max(la+ka*ta,lb+kb*tb),r=min(ra+ka*ta,rb+kb*tb);
    if(l<=r) ans=max(ans,r-l+1);
    printf("%lld\n",ans);
    return 0;
}