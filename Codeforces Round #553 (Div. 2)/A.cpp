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
const int maxn=55;
int n;
char s[maxn];
int p[26][26];

int main() {
    mem(p,0x3f);
    rep(i,0,25) {
        rep(j,i,25) {
            p[i][j]=p[j][i]=min(abs(j-i),abs(25-j)+i+1);
        }
    }
    scanf("%d",&n);
    scanf("%s",s+1);
    int ans=inf;
    for(int i=1;i+3<=n;i++) {
        int res=0;
        res+=p[s[i]-'A']['A'-'A'];
        res+=p[s[i+1]-'A']['C'-'A'];
        res+=p[s[i+2]-'A']['T'-'A'];
        res+=p[s[i+3]-'A']['G'-'A'];
        ans=min(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}