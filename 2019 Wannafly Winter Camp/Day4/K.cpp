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

const int maxn=1e5+5;
int n;
vector<int> e[maxn];
ll a[maxn];
ll dp[maxn];
vector<int> vec;
int root;

void dfs(int u,int fa) {
    dp[u]=a[u];
    ll temp=0;
    for(auto v:e[u]) {
        if(v==fa) continue;
        dfs(v,u);
        temp=max(dp[v],temp);
    }
    if(u!=root) dp[u]+=max(0ll,temp);
    // cout<<u<<" "<<dp[u]<<"\n";
}

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        ll val;
        scanf("%lld",&val);
        if(val==0) a[i]=0;
        else if(val>0) a[i]=(1ll<<(val-1));
        else a[i]=-(1ll<<(-val-1));
    }
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        scanf("%d",&root);
        dfs(root,0);
        vector<ll> res;
        for(auto v:e[root]) {
            if(dp[v]<=0) continue;
            res.pb(dp[v]);
        }
        sort(res.begin(),res.end());
        int sz=res.size();
        int cnt=4;
        // cout<<"fuck "<<dp[root]<<"\n";
        per(i,sz-1,0) {
            dp[root]+=res[i];
            cnt--;
            if(cnt==0) break;
        }
        // cout<<"fuck "<<dp[root]<<"\n";
        res.clear();
        // out
        vec.clear();
        if(dp[root]<0) {
            putchar('-');
            dp[root]*=-1;
        }
        if(dp[root]==0) puts("0");
        else {
            while(dp[root]) {
                if(dp[root]&1) vec.pb(1);
                else vec.pb(0);
                dp[root]>>=1;
            }
            int sz=vec.size();
            per(i,sz-1,0) printf("%d",vec[i]);
            puts("");
        }
    }
    return 0;
}