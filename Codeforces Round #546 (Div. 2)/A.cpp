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

const int maxn=105;
int l[maxn],r[maxn];
int n;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
    int k;
    scanf("%d",&k);
    rep(i,1,n) {
        if(k>=l[i]&&k<=r[i]) {
            return 0*printf("%d\n",n-i+1);
        }
    }
    return 0;
}