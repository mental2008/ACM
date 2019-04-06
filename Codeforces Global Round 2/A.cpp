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

const int maxn=3e5+5;
int c[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) {
        scanf("%d",&c[i]);
    }
    int ans=0;
    per(i,n,2) {
        if(c[i]!=c[1]) {
            ans=max(ans,i-1);
            break;
        }
    }
    rep(i,1,n-1) {
        if(c[i]!=c[n]) {
            ans=max(ans,n-i);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}