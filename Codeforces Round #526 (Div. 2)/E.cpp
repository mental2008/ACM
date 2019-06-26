#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const int maxn=5e5+5;
int n;
ll k;
char s[maxn];
char t[maxn];

int main() {
    scanf("%d%lld",&n,&k);
    scanf("%s",s+1);
    scanf("%s",t+1);
    ll m=1;
    ll ans=0;
    rep(i,1,n) {
        if(m<k) {
            m<<=1;
            if(s[i]==t[i]) m--;
            else if(s[i]=='b'&&t[i]=='a') m-=2;
            m=min(m,k);
        }
        ans+=m;
    }
    printf("%lld\n",ans);
    return 0;
}