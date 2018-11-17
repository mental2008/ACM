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
ll dp[maxn][maxn];
ll a[maxn];
int que[maxn];
int head,tail;
int n,k,x;

ll calc(int ql,int qr,int idx) {
    if(ql==0) ql++;
    if(ql>qr) return -1;
    int l=head,r=tail;
    ll ans=-1;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(que[mid]<ql) {
            l=mid+1;
        }
        else if(que[mid]>qr) {
            r=mid-1;
        }
        else {
            ans=dp[que[mid]][idx-1];
            r=mid-1;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d",&n,&k,&x);
    rep(i,1,n) scanf("%lld",&a[i]);
    mem(dp,-1);
    rep(i,1,x) {
        head=tail=1;
        que[head]=0;
        rep(j,1,n) {
            int idx=j-k;
            if(idx<0) idx=0;
            if(idx==0) dp[j][i]=max(dp[j][i],a[j]);
            ll val=calc(idx,j-1,i);
            if(val!=-1)
                dp[j][i]=max(val+a[j],dp[j][i]);
            if(dp[j][i-1]!=-1) {
                while(head<=tail&&dp[j][i-1]>=dp[que[tail]][i-1]) tail--;
                que[++tail]=j;
            }
            // cout<<j<<" "<<i<<" "<<dp[j][i]<<"\n";
        }
    }
    ll ans=-1;
    rep(i,n-k+1,n) ans=max(ans,dp[i][x]);
    if(ans==-1) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}