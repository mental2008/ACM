#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include<cmath>

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
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;
ll a[maxn];
int n,m;
ll l;

int main() {
    while(~scanf("%d%d%lld",&n,&m,&l)) {
        rep(i,1,n) scanf("%lld",&a[i]);
        ll ans=0;
        rep(i,1,n) {
            if(a[i]<=l) continue;
            int j;
            for(j=i+1;j<=n;++j) {
                if(a[j]<=l) {
                    break;
                }
            }
            ans++;
            i=j-1;
        }
        while(m--) {
            int o;
            scanf("%d",&o);
            if(o==1) {
                int p;
                ll d;
                scanf("%d%lld",&p,&d);
                if(a[p]>l) a[p]+=d;
                else {
                    a[p]+=d;
                    if(a[p]>l) {
                        if(p>=2&&a[p-1]>l&&p<n&&a[p+1]>l) {
                            ans--;
                        }
                        else if(p>=2&&a[p-1]<=l&&p<n&&a[p+1]<=l) {
                            ans++;
                        }
                        else if(p<n&&a[p+1]>l) {
                            ;
                        }
                        else if(p>=2&&a[p-1]>l) {
                            ;
                        }
                        else {
                            ans++;
                        }
                    }
                }
            }
            else {
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}