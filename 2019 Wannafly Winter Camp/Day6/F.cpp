#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)

typedef long long ll;
const ll mod=998244353ll;
const int maxn=1e3+5;
int n;
ll m;
ll a[maxn];
ll dp[40];
int num[40];
int bit;
int val;

ll dfs(int depth,int flag) {
    if(depth==-1) return 1;
    if(!flag&&dp[depth]!=-1) return dp[depth];
    int p=flag?num[depth]:1;
    ll res=0;
    rep(i,0,p) {
        if(bit==depth) {
            if(i==val) res=(res+dfs(depth-1,flag&&i==p))%mod;
        }
        else {
            res=(res+dfs(depth-1,flag&&i==p))%mod;
        }
    }
    if(!flag) dp[depth]=res%mod;
    return res;
}

int main() {
    scanf("%d%lld",&n,&m);
    rep(i,1,n) scanf("%lld",&a[i]);
    ll ans=0;
    ll temp=m;
    int index=0;
    while(temp) {
        num[index++]=temp%2;
        temp/=2;
    }
    // per(i,index-1,0) printf("%d",num[i]);
    // putchar('\n');
    // printf("%d\n",index);
    rep(i,1,n) {
        rep(j,i+1,n) {
            int p;
            per(k,40,0) {
                if(((a[i]>>k)&1)!=((a[j]>>k)&1)) {
                    p=k;
                    break;
                }
            }
            // printf("%d %d %d\n",i,j,p);
            if(m<(1<<p)) {
                if(a[i]>a[j]) ans=(ans+m)%mod;
            }
            else {
                mem(dp,-1);
                if(a[i]>a[j]) {
                    bit=p;
                    val=0;
                    // printf("%d %d %d %d\n",i,j,bit,val);
                    ll res=dfs(index-1,1)-1;
                    ans=(ans+res)%mod;
                }
                else {
                    bit=p;
                    val=1;
                    // printf("%d %d %d %d\n",i,j,bit,val);
                    ll res=dfs(index-1,1);
                    ans=(ans+res)%mod;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}