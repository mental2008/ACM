#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;

const int maxn=1e5+5;
int n,k;
priority_queue<ll> q;

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) {
        ll val;
        scanf("%lld",&val);
        q.push(val);
    }
    while(k--) {
        ll val=q.top();
        q.pop();
        if(val==0) break;
        val/=2;
        q.push(val);
    }
    ll ans=0;
    while(!q.empty()) {
        ll val=q.top();
        q.pop();
        ans+=val;
    }
    printf("%lld\n",ans);
    return 0;
}