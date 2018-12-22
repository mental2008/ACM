#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<bitset>

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
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=105;

string s[maxn];
int n,k;
bool vis[maxn];

void gao() {
    mem(vis,0);
    rep(i,1,k) {
        int leni=s[i].size();
        rep(j,1,k) {
            if(i==j||vis[j]==1) continue;
            int lenj=s[j].size();
            if(leni<lenj) {
                bool ok=true;
                rep(p,0,leni-1) {
                    if(s[i][p]!=s[j][p]) {
                        ok=false;
                        break;
                    }
                }
                if(ok) {
                    vis[j]=1;
                }
            }
        }
    }
}

ll quick_pow(ll a,ll x) {
    ll res=1;
    ll p=a;
    while(x) {
        if(x&1) res*=p;
        p*=p;
        x>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin>>caseCnt;
    rep(T,1,caseCnt) {
        cin>>n>>k;
        rep(i,1,k) cin>>s[i];
        gao();
        ll sum=quick_pow(2ll,n);
        ll ans=0;
        rep(i,1,k) {
            if(!vis[i]) {
                int len=s[i].size();
                ans+=quick_pow(2ll,n-len);
            }
        }
        cout<<"Case #"<<T<<": "<<sum-ans<<"\n";
    }
    return 0;
}