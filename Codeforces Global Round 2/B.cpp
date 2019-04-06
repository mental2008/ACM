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

const int maxn=1e3+5;
int n;
ll h;
int a[maxn];
int b[maxn];

int main() {
    scanf("%d%lld",&n,&h);
    rep(i,1,n) scanf("%d",&a[i]);
    per(i,n,1) {
        rep(j,1,i) b[j]=a[j];
        sort(b+1,b+1+i);
        ll res=0;
        for(int j=i;j>=2;j-=2) {
            res+=b[j];
        }
        if(i%2==1) res+=b[1];
        if(h>=res) return 0*printf("%d\n",i);
    }
    puts("0");
    return 0;
}