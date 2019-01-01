#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;
ll n;
vector<ll> vec;

int main() {
    scanf("%lld",&n);
    for(ll i=1;i*i<=n;++i) {
        if(n%i!=0) continue;
        if(i*i==n) {
            ll res=(n/i)*(n+2-i)/2;
            vec.pb(res);
        }
        else {
            ll res=(n/i)*(n+2-i)/2;
            vec.pb(res);
            res=i*(n+2-n/i)/2;
            vec.pb(res);
        }
    }
    sort(vec.begin(),vec.end());
    int len=vec.size();
    rep(i,0,len-1) {
        printf("%lld%c",vec[i],(i==len-1?'\n':' '));
    }
    return 0;
}