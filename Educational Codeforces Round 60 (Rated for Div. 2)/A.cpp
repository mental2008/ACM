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
typedef vector<int> vi;

const int maxn=1e5+5;
int n;
int a[maxn];
int dp[maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int Max=0;
    rep(i,1,n) Max=max(a[i],Max);
    int ans=0;
    a[0]=-1;
    rep(i,1,n) {
        if(a[i]==Max) dp[i]=1;
        if(a[i-1]==Max&&a[i]==Max) {
            dp[i]=dp[i-1]+1;
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}