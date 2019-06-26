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

const int maxn=105;
int n;
string s[maxn];
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>s[i];
    mem(cnt,0);
    rep(i,1,n) {
        cnt[s[i][0]-'a']++;
    }
    int ans=0;
    rep(i,0,25) {
        if(cnt[i]) {
            int x=cnt[i]/2;
            int y=cnt[i]-x;
            ans+=x*(x-1)/2+y*(y-1)/2;
        }
    }
    printf("%d\n",ans);
    return 0;
}