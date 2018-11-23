#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>

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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n;
ll m,a[maxn];

int main() {
    scanf("%d%lld",&n,&m);
    rep(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll ans=0;
    ll p=0;
    a[0]=0;
    per(i,n,1) {
        int j=i;
        for(;j>=1;--j) {
            if(a[i]!=a[j]) break;
        }
        ll need=a[i]-a[j];
        ll len=i-j;
        if(need>=len) {
            need-=len;
            ans+=len;
            if(p>=need) {
                p-=need;
                ans+=need;
            }
            else {
                ans+=need;
                p=0;
            }
        }
        else {
            p=p+len-need;
            ans+=need;
        }
        i=j+1;
    }
    ans+=p;
    ll sum=0;
    rep(i,1,n) sum+=a[i];
    printf("%lld\n",sum-ans);
    return 0;
}