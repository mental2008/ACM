#include<bits/stdc++.h>

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
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;
const int maxm=15;
int s[maxm][maxn];
int pos[maxm][maxn];
ull h[maxm][maxn];
ull base[maxn];
int n,m;
ull get(int index,int l,int r) {
    return h[index][r]-h[index][l]*base[r-l];
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m) {
        rep(j,0,n-1) {
            scanf("%d",&s[i][j]);
            pos[i][s[i][j]]=j;
        }
    }
    rep(i,1,m) {
        h[i][0]=0;
        rep(j,1,n) {
            h[i][j]=h[i][j-1]*998244353ll+s[i][j-1];
        }
    }
    base[0]=1;
    rep(i,1,n) base[i]=base[i-1]*998244353ll;
    ll ans=0;
    rep(i,0,n-1) {
        int l=1,r=inf;
        rep(j,1,m) r=min(r,n-pos[j][s[1][i]]);
        ll p;
        while(l<=r) {
            int mid=(l+r)>>1;
            bool judge=true;
            ull res=get(1,i,i+mid);
            rep(j,2,m) {
                ull temp=get(j,pos[j][s[1][i]],pos[j][s[1][i]]+mid);
                if(temp!=res) {
                    judge=false;
                    break;
                }
            }
            if(judge) {
                p=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans+=p;
    }
    printf("%lld\n",ans);
    return 0;
}
