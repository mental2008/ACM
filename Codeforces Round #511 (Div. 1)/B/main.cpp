#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

ll calc(ll n,ll m) {
    if(n==0) return 0;
    if(n==2) {
        ll ans=0;
        ll p=m/6,r=m%6;
        ans+=p*12;
        if(r==3) ans+=4;
        else if(r>=4) ans+=8;
        return ans;
    }
    else {
        ll ans=0;
        ll p=m/6,r=m%6;
        ans+=p*6;
        if(r==4) ans+=2;
        else ans+=4;
        return ans;
    }
}

int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(n>m) swap(n,m);
    if(n>=3&&m>=3) {
        ll ans=0;
        ll p=n/3,r=n%3;
        ll q=m/3,c=m%3;
        if(p%2==0||q%2==0) {
            ans+=p*q*9;
            ans+=calc(r,q*3/6*6);
            ans+=calc(c,p*3/6*6);
            ll temp1=q*3-(q*3/6*6);
            ll temp2=p*3-(p*3/6*6);
            printf("%lld\n",ans);
        }
        else {
            ans+=p*q*9;
            ans--;
        }

    }
    else {
        ll ans=calc(n,m);
        printf("%lld\n",ans);
    }
    return 0;
}
