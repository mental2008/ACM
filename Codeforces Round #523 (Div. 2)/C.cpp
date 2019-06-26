#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>

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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;
const int MAXN=1e6+5;

int n;
ll a[maxn];
ll dp[maxn];

vector<int> vec[MAXN];
void init() {
    rep(i,1,MAXN-1) vec[i].pb(1);
    rep(i,2,MAXN-1) {
        for(int j=i;j<MAXN;j+=i) {
            vec[j].pb(i);
        }
    }
}

int main() {
    init();
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    mem(dp,0);
    dp[0]=1;
    ll ans=0;
    rep(i,1,n) {
        int p=vec[a[i]].size();
        per(j,p-1,0) {
            if(vec[a[i]][j]<=i) {
                ans=(ans+dp[vec[a[i]][j]-1])%mod;
                dp[vec[a[i]][j]]=(dp[vec[a[i]][j]]+dp[vec[a[i]][j]-1])%mod;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}