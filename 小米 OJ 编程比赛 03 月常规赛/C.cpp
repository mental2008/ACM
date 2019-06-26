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

// void pre() {
//     int maxn=505;
//     ll p[maxn];
//     ll f1=1,f2=1;
//     int cnt=0;
//     p[++cnt]=2;
//     int i=0;
//     while(i<maxn) {
//         ll temp=f2;
//         f2=f2+f1;
//         f1=temp;
//         bool ok=true;
//         for(int i=1;i<=cnt;++i) {
//             if(f2%p[i]==0) {
//                 ok=false; break;
//             }
//         }
//         if(ok) p[++cnt]=f2;
//         ++i;
//     }
//     rep(i,1,20) printf("%d %lld\n",i,p[i]);
// }

const int maxn=8e6+5;
ll n,mod;
ll prim[maxn];
bool vis[maxn];
int cnt;
void init() {
    cnt=0;
    for(int i=2;i<maxn;++i) {
        if(!vis[i]) {
            prim[++cnt]=i;
        }
        for(int j=1;j<=cnt&&prim[j]*i<maxn;++j) {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}
struct matrix
{
    ll m[2][2];
};
matrix mul(matrix A,matrix B)
{
    matrix ret;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            ret.m[i][j]=0;
            for(int k=0;k<2;k++)
                ret.m[i][j]=(ret.m[i][j]+A.m[i][k]*B.m[k][j]%mod)%mod;
        }
    return ret;
}
matrix pow(matrix A,long long n)
{
    matrix ret;
    ret.m[0][0]=1;
    ret.m[0][1]=0;
    ret.m[1][0]=0;
    ret.m[1][1]=1;
    while(n)
    {
        if(n&1)
            ret=mul(ret,A);
        A=mul(A,A);
        n>>=1;
    }
    return ret;
}
ll solve(ll n) {
    matrix ans,A;
    ans.m[0][0]=1;
    ans.m[0][1]=0;
    A.m[0][0]=1;
    A.m[0][1]=1;
    A.m[1][0]=1;
    A.m[1][1]=0;
    ans=mul(ans,pow(A,n-1));
    return ans.m[0][0];
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}

ll Inv(ll a)
{
    ll d,x,y;
    d=exgcd(a,mod,x,y);
    return (x%mod+mod)%mod;
} 

int main() {
    init();
    while(~scanf("%lld%lld",&n,&mod)) {
        ll inv3=Inv(3ll);
        ll ans;
        if(n==1) ans=2ll;
        else if(n==2) ans=3ll;
        else ans=solve(prim[n]);
        ans=ans*inv3%mod;
        char o[10];
        rep(i,1,9) o[i]='*';
        per(i,9,1) {
            if(ans==0) break;
            ll temp=ans%10;
            o[i]=temp+'0';
            ans/=10;
        }
        rep(i,1,9) printf("%c",o[i]);
        puts("");
    }
    return 0;
}