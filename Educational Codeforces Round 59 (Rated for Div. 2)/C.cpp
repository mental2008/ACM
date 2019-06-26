#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=2e5+5;

int n,k;
ll a[maxn];
char s[maxn];

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%lld",&a[i]);
    scanf("%s",s+1);
    ll ans=0;
    rep(i,1,n) {
        int j=i;
        for(;j<=n;++j) {
            if(s[i]!=s[j]) {
                break;
            }
        }
        sort(a+i,a+j);
        int num=k;
        per(p,j-1,i) {
            ans+=a[p];
            num--;
            if(num==0) break;
        }
        i=j-1;
    }
    printf("%lld\n",ans);
    return 0;
}