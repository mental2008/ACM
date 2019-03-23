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

const int inf=0x3f3f3f3f;
const int maxn=105;
int n;
char s[maxn];
bool vis[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans=inf;
        mem(vis,0);
        bool sign=0;
        per(i,n,1) {
            if(s[i]=='<') { vis[i]=1; sign=1; }
            else {
                if(sign==1) vis[i]=1;
            }
        }
        int res=0;
        rep(i,1,n) if(!vis[i]) res++;
        ans=min(ans,res);
        mem(vis,0);
        sign=0;
        rep(i,1,n) {
            if(s[i]=='>') { vis[i]=1; sign=1; }
            else {
                if(sign==1) vis[i]=1;
            }
        }
        res=0;
        rep(i,1,n) if(!vis[i]) res++;
        ans=min(ans,res);
        printf("%d\n",ans);
    }
    return 0;
}