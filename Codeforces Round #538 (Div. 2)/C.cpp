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

const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+5;
ll n,b;
vi prime;
bool vis[maxn];
ll bb[maxn];
ll sum[maxn];
int cnt;

int main() {
    rep(i,2,maxn-1) {
        if(vis[i]==0) {
            prime.pb(i);
            for(int j=i*2;j<maxn;j+=i) {
                vis[j]=1;
            }
        }
    }
    scanf("%lld%lld",&n,&b);
    int len=prime.size();
    cnt=0;
    rep(i,0,len-1) {
        if(b%prime[i]==0) {
            cnt++;
            bb[cnt]=prime[i];
            while(b%prime[i]==0) {
                sum[cnt]++;
                b/=prime[i];
            }
        }
    }
    if(b!=1) {
        cnt++;
        bb[cnt]=b;
        sum[cnt]=1;
    }
    ll ans=INF;
    rep(i,1,cnt) {
        ll res=0;
        for(ll j=1;n/bb[i]>=j;) {
            j*=bb[i];
            res+=n/j;
        }
        ans=min(ans,res/sum[i]);
    }
    printf("%lld\n",ans);
    return 0;
}