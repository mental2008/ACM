#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const int maxn=5e5+5;
int n,c;
int vis[maxn];
int cnt;
vector<int> e[maxn];
vector<int> vec;
int pre[maxn];

int main() {
    scanf("%d%d",&n,&c);
    cnt=0;
    pre[0]=0;
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        pre[i]=pre[i-1]+(val==c);
        if(val==c) continue;
        if(!vis[val]) vis[val]=++cnt;
        e[vis[val]].pb(i);
    }
    int ans=pre[n];
    rep(i,1,cnt) {
        int len=e[i].size();
        vec.clear();
        vec.pb(0);
        rep(j,0,len-1) {
            vec.pb(1);
            if(j<len-1) vec.pb(-pre[e[i][j+1]]+pre[e[i][j]-1]);
        }
        len=vec.size();
        rep(j,1,len-1) {
            vec[j]=max(vec[j],vec[j-1]+vec[j]);
            if(vec[j]<0) vec[j]=0;
            ans=max(ans,pre[n]+vec[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}