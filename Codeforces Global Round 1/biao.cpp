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

ll gcd(ll x,ll y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    int n=25;
    rep(i,1,n) {
        ll p=(1<<i)-1;
        ll o=1;
        rep(x,1,p) {
            ll y=p^x;
            if(x>y) break;
            o=max(o,gcd(x,y));
        }
        cout<<o<<",";
    }
    puts("");
    return 0;
}