#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
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
const ll mod=1e9+7;
const int maxn=105;
int n;
string s[maxn];

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin>>caseCnt;
    while(caseCnt--) {
        cin>>n;
        rep(i,1,n) cin>>s[i];
        auto cmp=[=](string x,string y) {
            int lenx=x.size();
            int leny=y.size();
            return lenx<leny;
        };
        sort(s+1,s+1+n,cmp);
        bool ok=true;
        rep(i,1,n-1) {
            int lenx=s[i].size();
            int leny=s[i+1].size();
            bool judge=false;
            rep(j,0,leny-lenx) {
                if(s[i]==s[i+1].substr(j,lenx)) {
                    judge=true;
                    break;
                }
            }
            if(judge==false) {
                ok=false;
                break;
            }
        }
        
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}