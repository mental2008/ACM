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
const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+5;
int n;
ll a[maxn];
struct Node {
    ll x;
    ll cnt;
} node[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%d",&n);
        rep(i,1,n) scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        ll res=inf;
        rep(i,1,n-1) {
            res=min(a[i+1]-a[i],res);
        }
        int index=0;
        rep(i,1,n) {
            int j;
            ll cnt=0;
            for(j=i;j<=n;++j) {
                if(a[j]!=a[i]) break;
                cnt++;
            }
            node[++index].x=a[i];
            node[index].cnt=cnt;
            i=j-1;
        }
        ll ans=0;
        if(res==0) {
            rep(i,1,index) {
                ll cnt=node[i].cnt;
                if(cnt>=2) {
                    ans=(ans+cnt*(cnt-1)/2);
                }
            }
        }
        else {
            rep(i,1,index-1) {
                if(res==node[i+1].x-node[i].x) {
                    ans=(ans+node[i].cnt*node[i+1].cnt);
                }
            }
        }
        printf("%lld %lld\n",res,ans);
    }
    return 0;
}