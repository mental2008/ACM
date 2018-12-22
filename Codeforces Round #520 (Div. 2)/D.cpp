#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int n;
bool vis[maxn];

int main() {
    scanf("%d",&n);
    mem(vis,0);
    ll ans=0;
    for(int i=2;i<=n;++i) {
        if(vis[i]==0) {
            for(int j=2*i;j<=n;j+=i) {
                vis[i]=1;
                ans+=(4ll*j/i);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}