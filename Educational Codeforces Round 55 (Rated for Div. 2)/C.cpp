#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const int maxn=1e5+5;
int n,m;
vector<int> e[maxn];
vector<int> pre[maxn];
vector<int> vec;
bool cmp(int x,int y) {
    return x>y;
}
struct Node {
    int id;
    int sz;
    bool operator<(const Node& e) const {
        return sz>e.sz;
    }
} node[maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) {
        int s,r;
        scanf("%d%d",&s,&r);
        e[s].pb(r);
        pre[s].pb(0);
    }
    int k=0;
    rep(i,1,m) {
        sort(e[i].begin(),e[i].end(),cmp);
        int len=e[i].size();
        node[i].id=i;
        node[i].sz=len;
        k=max(k,len-1);
        if(len>0) pre[i][0]=e[i][0];
        rep(j,1,len-1) {
            pre[i][j]=pre[i][j-1]+e[i][j];
        }
    }
    sort(node+1,node+1+m);
    int ans=0;
    rep(index,0,k) {
        vec.clear();
        rep(j,1,m) {
            if(node[j].sz<index+1) break;
            vec.pb(pre[node[j].id][index]);
        }
        sort(vec.begin(),vec.end(),cmp);
        int res=0;
        int len=vec.size();
        rep(j,0,len-1) {
            if(vec[j]<0) break;
            res+=vec[j];
        }
        ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}