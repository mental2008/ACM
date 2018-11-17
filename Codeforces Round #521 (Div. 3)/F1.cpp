#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)

typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=5005;
ll dp[maxn];
ll a[maxn];
int cnt[maxn];
int que[maxn];
int head,tail;
int n,k,x;

void solve(ll limit) {
    head=tail=1;
    que[head]=0;
    dp[0]=0;
    cnt[0]=0;
    rep(i,1,n) dp[i]=-INF;
    rep(i,1,n) {
        while(head<=tail&&que[head]<i-k) head++;
        int idx=que[head];
        if(idx!=-1) {
            if(dp[i]<dp[idx]+a[i]-limit||(dp[i]==dp[idx]+a[i]-limit&&cnt[i]<cnt[idx]+1)) {
                dp[i]=dp[idx]+a[i]-limit;
                cnt[i]=cnt[idx]+1;
            }
        }
        while(head<=tail&&(dp[i]>dp[que[tail]]||(dp[i]==dp[que[tail]&&cnt[i]>=cnt[que[tail]]]))) tail--;
        que[++tail]=i;
    }
    per(i,n,n-k+1) {
        if(dp[n]<dp[i]||(dp[n]==dp[i]&&cnt[n]<cnt[i])) {
            dp[n]=dp[i];
            cnt[n]=cnt[i];
        }
    }
}
int main() {
    scanf("%d%d%d",&n,&k,&x);
    rep(i,1,n) scanf("%lld",&a[i]);
    if(n>x*k+k-1) return 0*puts("-1");
    ll l=0,r=5050ll*1e9;
    ll ans=-INF;
    while(l<=r) {
        ll mid=(l+r)>>1;
        solve(mid);
        if(cnt[n]>=x) {
            l=mid+1;
            ans=dp[n]+mid*x;
        }
        else {
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}