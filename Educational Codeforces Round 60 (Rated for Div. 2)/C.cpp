#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+5;
int n;
ll x1,y11;
ll x2,y2;
char s[maxn];
ll prex[maxn];
ll prey[maxn];

bool solve(ll k) {
    ll xn=x2-x1;
    ll yn=y2-y11;
    ll x=(k/n)*prex[n]+prex[k%n];
    ll y=(k/n)*prey[n]+prey[k%n];
    // cout << x << " "<<y <<"\n";
    if(abs(x-xn)+abs(y-yn)<=k) return true;
    return false;
}

int main() {
    scanf("%lld%lld",&x1,&y11);
    scanf("%lld%lld",&x2,&y2);
    scanf("%d",&n);
    scanf("%s",s+1);
    prex[0]=prey[0]=0;
    rep(i,1,n) {
        prex[i]=prex[i-1];
        prey[i]=prey[i-1];
        if(s[i]=='U') prey[i]++;
        if(s[i]=='D') prey[i]--;
        if(s[i]=='L') prex[i]--;
        if(s[i]=='R') prex[i]++;
    }
    ll l=1,r=inf;
    ll ans=-1;
    while(l<=r) {
        ll mid=(l+r)>>1;
        if(solve(mid)) {
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}