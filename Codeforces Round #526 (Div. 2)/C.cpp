#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
char s[maxn];
int n;
int a[maxn];
int num[maxn];
int pre[maxn];
int cnt;

int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    pre[0]=0;
    cnt=0;
    rep(i,1,n) {
        pre[i]=pre[i-1]+(s[i]=='b');
        if(s[i]=='a') {
            if(cnt==0) {
                a[++cnt]=i;
                num[cnt]=1;
            }
            else {
                if(pre[i]-pre[a[cnt]]==0) {
                    num[cnt]++;
                }
                else {
                    a[++cnt]=i;
                    num[cnt]=1;
                }
            }
        }
    }
    ll ans=1;
    rep(i,1,n) {
        ans=ans*(num[i]+1)%mod;
    }
    ans--;
    ans=(ans%mod+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}