#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1005;
int n;
ll a[maxn];
vector<int> ans;
ll x[maxn];

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(k,1,n) {
        mem(x,0x3f);
        bool ok=true;
        rep(i,1,n) {
            int p=(i-1)%k;
            if(x[p]==0x3f3f3f3f3f3f3f3f) {
                x[p]=a[i]-a[i-1];
            }
            else if(x[p]!=a[i]-a[i-1]) {
                ok=false;
                break;
            }
        }
        if(ok) ans.pb(k);
    }
    int len=ans.size();
    printf("%d\n",len);
    rep(i,0,len-1) {
        printf("%d%c",ans[i],(i==len-1?'\n':' '));
    }
    return 0;
}
