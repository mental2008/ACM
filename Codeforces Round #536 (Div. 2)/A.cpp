#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pr(x) cout<<x<<"\n";
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);

const int maxn=505;
int n;
char s[maxn][maxn];
int p[4]={-1,-1,1,1};
int q[4]={-1,1,-1,1};

bool judge(int x,int y) {
    int cnt=0;
    rep(i,0,3) {
        int xx=x+p[i];
        int yy=y+q[i];
        if(xx<0||xx>=n||yy<0||yy>=n) continue;
        if(s[xx][yy]=='X') cnt++;
    }
    return cnt==4;
}

int main() {
    scanf("%d",&n);
    rep(i,0,n-1) scanf("%s",s[i]);
    int ans=0;
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            if(s[i][j]=='X'&&judge(i,j)) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}