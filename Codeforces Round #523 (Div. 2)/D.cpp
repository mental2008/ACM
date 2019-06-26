#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>

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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=1e5+5;
int n;
ll x,y;
struct Node {
    ll l,r;
    Node() {}
    Node(ll _l,ll _r) {
        l=_l;
        r=_r;
    }
    bool operator<(const Node& e) const {
        if(l==e.l) return r<e.r;
        return l<e.l;
    }
} node[maxn];
set<int> st;
map<int,int> vis;

int main() {
    scanf("%d%lld%lld",&n,&x,&y);
    rep(i,1,n) {
        scanf("%lld%lld",&node[i].l,&node[i].r);
    }
    sort(node+1,node+1+n);
    ll ans=0;
    rep(i,1,n) {
        auto pos=st.lower_bound(node[i].l);
        if(pos==st.begin()) {
            ll res=(y*(node[i].r-node[i].l)%mod+x)%mod;
            ans=(ans+res)%mod;
            st.insert(node[i].r);
            vis[node[i].r]++;
        }
        else {
            pos--;
            if(y*(node[i].l-*pos)>x) {
                ll res=(y*(node[i].r-node[i].l)%mod+x)%mod;
                ans=(ans+res)%mod;
                st.insert(node[i].r);
                vis[node[i].r]++;
            }
            else {
                ll res=y*(node[i].r-*pos)%mod;
                ans=(ans+res)%mod;
                vis[*pos]--;
                if(vis[*pos]==0) st.erase(pos);
                st.insert(node[i].r);
                vis[node[i].r]++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}