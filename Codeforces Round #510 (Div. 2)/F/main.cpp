#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
vector<int> G[maxn];
int n,k;
int ans;
int depth[maxn];

int dfs(int u,int pre) {
    int len=(int)G[u].size();
    if(len==1) {
        ans++;
        return depth[u];
    }
    vector<int> vec;
    rep(i,0,len-1) {
        int v=G[u][i];
        if(v==pre) continue;
        depth[v]=depth[u]+1;
        int res=dfs(v,u);
        vec.pb(res);
    }
    len=(int)vec.size();
    if(len==1) return vec[0];
    sort(vec.begin(),vec.end());
    rep(i,1,len-1) {
        if(vec[i]+vec[i-1]-2*depth[u]<=k) ans--;
        else {
            return vec[i-1];
        }
    }
    return vec[len-1];
}

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    ans=0;
    rep(i,1,n) {
        int len=(int)G[i].size();
        if(len!=1) {
            depth[i]=0;
            dfs(i,i);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
