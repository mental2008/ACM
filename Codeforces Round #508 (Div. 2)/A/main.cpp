#include<bits/stdc++.h>
using namespace std;
#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
int n,k;
char s[maxn];
int cnt[30];

int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    rep(i,0,n-1) {
        cnt[s[i]-'A']++;
    }
    int ans=INF;
    rep(i,0,k-1) {
        ans=min(ans,cnt[i]);
    }
    printf("%d\n",ans*k);
    return 0;
}
