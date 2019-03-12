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
int n,m;
int p[maxn];
vi e[maxn];
set<int> st;
set<int> temp;

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&p[i]);
    rep(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[v].pb(u);
    }
    for(auto x:e[p[n]]) {
        st.insert(x);
    }
    int ans=0;
    int k=n-1;
    while(k>=1) {
        if(st.empty()) break;
        if(st.find(p[k])!=st.end()) {
            ans++;
        }
        else {
            temp.clear();
            for(auto x:st) temp.insert(x);
            st.clear();
            for(auto x:e[p[k]]) {
                if(temp.find(x)!=temp.end()) {
                    st.insert(x);
                }
            }
        }
        k--;
    }
    printf("%d\n",ans);
    return 0;
}