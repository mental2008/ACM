#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pr(x) cout<<x<<"\n";
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=1e5+5;
int n,m;
vi e[maxn];
bool vis[maxn];
priority_queue<int,vector<int>,greater<int> > Q;
vi ans;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    Q.push(1);
    vis[1]=1;
    while(!Q.empty()) {
        int u=Q.top();
        Q.pop();
        ans.pb(u);
        for(auto v:e[u]) {
            if(!vis[v]) {
                vis[v]=1;
                Q.push(v);
            }
        }
    }
    int len=ans.size();
    rep(i,0,len-1) {
        printf("%d%c",ans[i],(i==len-1?'\n':' '));
    }
    return 0;
}