#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int n,m;
char ch[maxn][maxn];
char s[maxn][maxn];
int p[8]={0,0,1,1,1,-1,-1,-1};
int q[8]={1,-1,0,-1,1,0,1,-1};
bool judge() {
    rep(i,0,n-1) rep(j,0,m-1) if(ch[i][j]!=s[i][j]) return false;
    return true;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        rep(i,0,n-1) {
            scanf("%s",ch[i]);
        }
        rep(i,0,n-1) rep(j,0,m-1) s[i][j]='.';
        rep(i,0,n-1) {
            rep(j,0,m-1) {
                if(i-1<0||i+1>=n||j-1<0||j+1>=m) continue;
                bool ok=true;
                rep(k,0,7) {
                    if(ch[i+p[k]][j+q[k]]=='.') {
                        ok=false;
                        break;
                    }
                }
                if(ok) rep(k,0,7) s[i+p[k]][j+q[k]]='#';
            }
        }
        bool ans=judge();
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
