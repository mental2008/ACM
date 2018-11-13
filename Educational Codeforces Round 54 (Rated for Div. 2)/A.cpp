#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>

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
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=2e5+5;
int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    while(cin>>n) {
        cin>>s;
        bool ok=false;
        rep(i,0,n-2) {
            if(s[i]>s[i+1]) {
                string ans=s.substr(0,i)+s.substr(i+1,n-i-1);
                cout<<ans<<"\n";
                ok=true;
                break;
            }
        }
        if(!ok) cout<<s.substr(0,n-1)<<"\n";
    }
    return 0;
}