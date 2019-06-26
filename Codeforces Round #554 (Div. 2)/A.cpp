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

const int maxn=1e5+5;
int n,m;
ll a[maxn];
ll b[maxn];

int main() {
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,m) scanf("%lld",&b[i]);
    int odd=0,even=0;
    int odd2=0,even2=0;
    rep(i,1,n) {
        if(a[i]%2) odd++;
        else even++;
    }
    rep(i,1,m) {
        if(b[i]%2) odd2++;
        else even2++;
    }
    int ans=min(odd,even2)+min(even,odd2);
    printf("%d\n",ans);
    return 0;
}