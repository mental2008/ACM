#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>

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
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=3e5+5;

int n;
ll k;
ll x[maxn];
ll y[maxn];
ll ra,rb;

bool solve(ll a,ll b,ll p,ll q) {
    ra=rb=inf;
    ll m=min(q,p+1);
    if(a<=k&&m*k>=q&&(k-a)+(m-1)*k>=p) {
        rb=max(1ll,q-(m-1)*k);
    }
    m=min(q,p);
    if(a<=k&&m*k>=q&&(k-a)+m*k>=p) {
        ra=max(1ll,p-(k-a)-(m-1)*k);
    }
    m=min(q,p);
    if(b<=k&&m*k>=p&&(k-b)+m*k>=q) {
        rb=min(rb,max(1ll,q-(k-b)-(m-1)*k));
    }
    m=min(q+1,p);
    if(b<=k&&m*k>=p&&(k-b)+(m-1)*k>=q) {
        ra=min(ra,max(1ll,p-(m-1)*k));
    }
    if(ra==inf&&rb==inf) return false;
    return true;
}

int main() {
    scanf("%d%lld",&n,&k);
    rep(i,1,n) scanf("%lld",&x[i]);
    rep(i,1,n) scanf("%lld",&y[i]);
    ra=rb=0;
    rep(i,1,n) {
        bool state=solve(ra,rb,x[i],y[i]);
        // cout<<ra<<" "<<rb<<"\n";
        if(state==false) return 0*puts("NO");
    }
    puts("YES");
    return 0;
}