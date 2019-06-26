#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>

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
const int maxn=1e5+5;

int n;
set<pii> st;

int main() {
    scanf("%d",&n);
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        st.insert(mp(u,v));
    }
    int ans=0;
    rep(i,1,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        if(st.find(mp(u,v))==st.end()) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}