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
struct Node {
    int id;
    ll a,c;
    bool operator<(const Node& e) const {
        if(c==e.c) return id<e.id;
        return c<e.c;
    }
} node[maxn];
set<Node> st;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%lld",&node[i].a);
    rep(i,1,n) scanf("%lld",&node[i].c);
    rep(i,1,n) {
        node[i].id=i;
        st.insert(node[i]);
    }
    rep(i,1,m) {
        ll t,d;
        scanf("%lld%lld",&t,&d);
        ll ans=0;
        if(node[t].a>=d) {
            st.erase(node[t]);
            ans=node[t].c*d;
            node[t].a-=d;
            d=0;
            if(node[t].a!=0) st.insert(node[t]);
        }
        else {
            st.erase(node[t]);
            // printf("%lld %lld\n",t,node[t].a);
            d-=node[t].a;
            ans=node[t].c*node[t].a;
            node[t].a=0;
            if(node[t].a!=0) st.insert(node[t]);
            while(d!=0) {
                if(st.empty()) break;
                auto pos=st.begin();
                if((*pos).a==0) {
                    st.erase(pos);
                    continue;
                }
                int index=(*pos).id;
                st.erase(node[index]);
                if(node[index].a>=d) {
                    // printf("%d %lld\n",index,d);
                    ans+=node[index].c*d;
                    node[index].a-=d;
                    d=0;
                    if(node[index].a!=0) st.insert(node[index]);
                }
                else {
                    // printf("%d %lld\n",index,node[index].a);
                    ans+=node[index].c*node[index].a;
                    d-=node[index].a;
                    node[index].a=0;
                    if(node[index].a!=0) st.insert(node[index]);
                }
            }
            if(d!=0) ans=0;
        }
        printf("%lld\n",ans);
    }

    return 0;
}