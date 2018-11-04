#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>

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
const int maxn=1e5+5;
int n;
ll a[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        rep(i,1,n) scanf("%lld",&a[i]);
        ll ans=0;
        sort(a+1,a+1+n);
        rep(i,1,n) {
            int j;
            ll cnt=0;
            for(j=i;j<=n;++j) {
                if(a[j]!=a[i]) break;
                cnt++;
            }
            i=j-1;
            ans+=cnt-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}