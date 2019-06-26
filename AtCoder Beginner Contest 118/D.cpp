#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const int maxn=1e4+5;
int n,m;
int p[]={0,2,5,5,4,5,6,3,7,6};
int vis[10];
int ans[maxn];
int lar,sma;
set<pii> st;
map<pii,bool> mt;

bool dfs(int res,int len) {
    if(res<sma*len) return false;
    if(lar*len<res) return false;
    if(st.find(mp(res,len))!=st.end()) return mt[mp(res,len)];
    if(len==1) {
        per(i,9,1) {
            if(vis[i]&&p[i]==res) {
                ans[len]=i;
                st.insert(mp(res,len));
                mt[mp(res,len)]=true;
                return true;
            }
        }
        st.insert(mp(res,len));
        mt[mp(res,len)]=false;
        return false;
    }
    per(i,9,1) {
        if(vis[i]&&dfs(res-p[i],len-1)) {
            ans[len]=i;
            st.insert(mp(res,len));
            mt[mp(res,len)]=true;
            return true;
        }
    }
    st.insert(mp(res,len));
    mt[mp(res,len)]=false;
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        int val;
        scanf("%d",&val);
        vis[val]=1;
    }
    int need=inf;
    sma=inf;
    lar=0;
    rep(i,1,9) {
        if(vis[i]) {
            need=min(need,p[i]);
            sma=min(sma,p[i]);
            lar=max(lar,p[i]);
        }
    }
    int len=n/need;
    while(!dfs(n,len)) {
        len--;
    }
    per(i,len,1) putchar('0'+ans[i]);
    puts("");
    return 0;
}