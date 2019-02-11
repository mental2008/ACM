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
typedef vector<int> vi;

const int maxn=2e5+5;
ll a[maxn];
int n,m,k;
struct Node {
    ll val;
    int id;
    bool operator<(const Node& e) const {
        if(val==e.val) return id<e.id;
        return val>e.val;
    }
} node[maxn];
int sign[maxn];

int main() {
    while(~scanf("%d%d%d",&n,&m,&k)) {
        rep(i,1,n) {
            scanf("%lld",&a[i]);
            node[i].id=i;
            node[i].val=a[i];
        }
        sort(node+1,node+1+n);
        mem(sign,0);
        ll ans=0;
        rep(i,1,k*m) {
            sign[node[i].id]=1;
            ans+=node[i].val;
        }
        printf("%lld\n",ans);
        int cnt=0;
        int kk=0;
        rep(i,1,n) {
            if(sign[i]) cnt++;
            if(cnt==m) {
                cnt=0;
                kk++;
                if(kk==k) break;
                printf("%d ",i);
            }
        }
        puts("");
    }
    return 0;
}