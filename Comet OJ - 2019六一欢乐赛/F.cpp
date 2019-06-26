#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

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

const int maxn=1005;
int n,m,q;
set<pii> st;

int main() {
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n-1) {
        rep(j,1,m-1) {
            st.insert(mp(i,j));
        }
    }
    while(q--) {
        int x,y;
        scanf("%d%d",&x,&y);
        st.erase(mp(x,y));
        st.erase(mp(x-1,y));
        st.erase(mp(x,y-1));
        st.erase(mp(x-1,y-1));
        int ans=(int)st.size();
        printf("%d\n",ans);
    }
    return 0;
}