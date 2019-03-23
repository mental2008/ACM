#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=3e5+5;
int n,k;
struct Node {
    ll t,b;
    bool operator<(const Node& e) const {
        return t<e.t;
    }
} cc[maxn];
bool cmp(Node x,Node y) {
    return x.b>y.b;
}
multiset<Node> st;

int main() {
    scanf("%d%d",&n,&k);
    ll mx=0;
    rep(i,1,n) scanf("%lld%lld",&cc[i].t,&cc[i].b);
    rep(i,1,n) mx=max(mx,cc[i].b);
    sort(cc+1,cc+1+n,cmp);
    ll ans=0;
    int id=1;
    ll res=0;
    per(i,mx,1) {
        while(cc[id].b>=i&&id<=n) {
            st.insert(cc[id]);
            // cout<<i<<" "<<cc[id].t<<" "<<cc[id].b<<"\n";
            res+=cc[id].t;
            if(st.size()>k) {
                auto pos=st.begin();
                res-=(*pos).t;
                st.erase(pos);
            }
            id++;
        }
        ans=max(ans,res*i);
    }
    printf("%lld\n",ans);
    return 0;
}