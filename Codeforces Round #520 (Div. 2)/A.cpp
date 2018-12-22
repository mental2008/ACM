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
const int maxn=1005;

int n;
int a[maxn];
bool vis[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int ans=0;
    mem(vis,0);
    if(a[1]==1) {
        int res=0;
        rep(i,2,n) {
            if(a[i]!=a[i-1]+1) break;
            res++;
        }
        ans=max(ans,res);
    }
    if(a[n]==1000) {
        int res=0;
        per(i,n-1,1) {
            if(a[i]+1!=a[i+1]) break;
            res++;
        }
        ans=max(ans,res);
    }
    rep(i,1,n) {
        int j=i;
        for(;j<=n;++j) {
            if(a[i]+j-i!=a[j]) break;
        }
        if(i==j-1) continue;
        ans=max(ans,j-i-2);
        i=j-1;
    }
    printf("%d\n",ans);
    return 0;
}