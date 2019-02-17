#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=3e5+5;
int n;
ll a[maxn];
ll ans;
ll b[maxn];
map<ll,int> mp;

int main() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    b[0]=0;
    rep(i,1,n) b[i]=b[i-1]^a[i];
    // rep(i,1,n) {
    //     printf("%d %lld\n",i,b[i]);
    // }
    rep(i,0,n) {
        if(i%2==0) {
            mp[b[i]]++;
        }
    }
    ll ans=0;
    for(auto it:mp) {
        int cnt=it.second;
        ans+=1ll*cnt*(cnt-1)/2;
    }
    mp.clear();
    rep(i,0,n) {
        if(i%2==1) {
            mp[b[i]]++;
        }
    }
    for(auto it:mp) {
        int cnt=it.second;
        ans+=1ll*cnt*(cnt-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}