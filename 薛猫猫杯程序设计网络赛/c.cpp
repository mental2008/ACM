#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>

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
const int maxn=1e5+5;
int n,m;
ll a[maxn];

bool judge(ll limit) {
    ll res=0;
    int cnt=0;
    ll lst=0;
    rep(i,1,n) {
        res+=a[i];
        if(res!=a[i])
            cnt++;
        if(res>=limit) {
            lst=res;
            res=0;
            continue;
        }
    }
    if(res) cnt++;
    if(res+lst<limit) return false;
    return cnt<=m;
}

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d%d",&n,&m);
        rep(i,1,n) scanf("%lld",&a[i]);
        ll l=0,r=inf;
        ll ans;
        while(l<=r) {
            ll mid=(l+r)>>1;
            if(judge(mid)) {
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}