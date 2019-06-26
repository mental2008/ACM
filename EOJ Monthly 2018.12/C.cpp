#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
typedef long long ll;
const ll mod=1e9+7;
const int S=2005;
const int maxn=5e5+5;
char s[S];
int n;
char o[5];
set<int> st[10][10];
ll vec[10][10][S];
ll vis[S][10][10];
ll fact[S];
ll fiv[S];
ll inv[S];

void init() {
    fact[0]=fact[1]=1;
    fiv[0]=fiv[1]=1;
    inv[1]=1;
    rep(i,2,S-1) {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        fiv[i]=inv[i]*fiv[i-1]%mod;
    }
    mem(vis,-1);
}
ll C(ll m,ll k) {
    if(m<k|k<0) return 0;
    return (fact[m]*fiv[k]%mod)*fiv[m-k]%mod;
}

int main() {
    init();
    scanf("%s",s);
    n=strlen(s);
    rep(i,0,n-1) {
        rep(j,i+1,n-1) {
            st[s[i]-'0'][s[j]-'0'].insert(i);
            vec[s[i]-'0'][s[j]-'0'][i]++;;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--) {
        int m;
        scanf("%d",&m);
        scanf("%s",o);
        if(m>n||m==1) puts("0");
        else {
            if(vis[m-2][o[0]-'0'][o[1]-'0']!=-1) {
                printf("%lld\n",vis[m-2][o[0]-'0'][o[1]-'0']);
                continue;
            }
            ll ans=0;
            auto pos=st[o[0]-'0'][o[1]-'0'].lower_bound(m-2);
            while(pos!=st[o[0]-'0'][o[1]-'0'].end()) {
                int x=(*pos);
                ll res=C(x,m-2)*vec[o[0]-'0'][o[1]-'0'][x]%mod;
                ans=(ans+res)%mod;
                pos++;
            }
            vis[m-2][o[0]-'0'][o[1]-'0']=ans;
            printf("%lld\n",ans);
        }
    }
    return 0;
}