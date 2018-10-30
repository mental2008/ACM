#include<bits/stdc++.h>

using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll mod=998244353ll;
const int maxn=1005;
int n,m;
struct Node {
    ll val;
    int p,q;
    bool operator<(const Node& e) const {
        return val<e.val;
    }
};
vector<Node> vec;
ll a[maxn][maxn];
ll dp[maxn*maxn];
ll inv[maxn*maxn];
ll f1[maxn*maxn];
ll f2[maxn*maxn];
ll f3[maxn*maxn];
ll f4[maxn*maxn];
ll f[maxn*maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) rep(j,1,m) scanf("%lld",&a[i][j]);
    rep(i,1,n) rep(j,1,m) {
        Node node;
        node.val=a[i][j];
        node.p=i;
        node.q=j;
        vec.push_back(node);
    }
    sort(vec.begin(),vec.end());
    int r,c;
    scanf("%d%d",&r,&c);
    int len=(int)vec.size();
    int index;
    rep(i,0,len-1) {
        if(vec[i].p==r&&vec[i].q==c) {
            index=i;
            break;
        }
    }
    inv[1]=1;
    rep(i,2,index) {
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    f1[0]=f2[0]=f3[0]=f4[0]=f[0]=0;
    rep(i,0,index) {

        int pre=-1;
        int l=0,r=i;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(vec[mid].val<vec[i].val) {
                pre=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        if(pre==-1) dp[i]=0;
        else {
            int cnt=pre+1;
            dp[i]=(vec[i].p*vec[i].p+vec[i].q*vec[i].q)%mod;
            dp[i]=dp[i]*cnt%mod;
            dp[i]=(dp[i]+f3[pre]+f4[pre])%mod;
            ll temp=vec[i].p*f1[pre]%mod;
            dp[i]=(dp[i]+temp)%mod;
            temp=vec[i].q*f2[pre]%mod;
            dp[i]=(dp[i]+temp)%mod;
            dp[i]=(dp[i]+f[pre])%mod;
            if(i!=0) dp[i]=(dp[i]*inv[cnt])%mod;
        }
        f1[i]=f1[i-1]-2*vec[i].p;
        f2[i]=f2[i-1]-2*vec[i].q;
        f3[i]=f3[i-1]+vec[i].p*vec[i].p;
        f4[i]=f4[i-1]+vec[i].q*vec[i].q;
        f1[i]=(f1[i]%mod+mod)%mod;
        f2[i]=(f2[i]%mod+mod)%mod;
        f3[i]=(f3[i]%mod+mod)%mod;
        f4[i]=(f4[i]%mod+mod)%mod;
        f[i]=(dp[i]+f[i-1])%mod;
    }
    printf("%lld\n",dp[index]);
    return 0;
}
