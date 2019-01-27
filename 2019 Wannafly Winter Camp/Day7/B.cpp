#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
typedef long long ll;

const int maxn=1e4+5;
vector<int> e[maxn];
int used[maxn];
int p[maxn];
int n,m;
int x;

bool find(int u) {
    for(auto v:e[u]) {
        if(v<=x) continue;
        if(!used[v]) {
            used[v]=1;
            if(p[v]==-1||find(p[v])) {
                p[v]=u;
                return true;
            }
        }
    }
    return false;
}

bool solve() {
    mem(p,-1);
    rep(i,0,x) {
        mem(used,0);
        if(!find(i)) return false;
    }
    // rep(i,0,x) cout<<i<<" "<<p[i]<<"\n";
    return true;
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r) {
        int mid=(l+r)>>1;
        x=mid;
        if(solve()) {
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    printf("%d\n",ans+1);
    return 0;
}