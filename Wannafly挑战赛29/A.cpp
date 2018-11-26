#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;

const int maxn=1e5+5;
ll n,m;
ll a[maxn];
multiset<ll> st;

int main() {
    scanf("%lld%lld",&n,&m);
    rep(i,1,m) scanf("%lld",&a[i]);
    sort(a+1,a+1+m);
    int index=m;
    st.insert(n);
    while(index) {
        if(st.empty()) break;
        auto pos=st.end();
        if(st.size()+m-index>m) break;
        pos--;
        if((*pos)==a[index]) {
            st.erase(pos);
            index--;
            continue;
        }
        if((*pos)<a[index]) {
            return 0*puts("ham");
        }
        ll p=(*pos)/2ll,q=(*pos)-p;
        st.erase(pos);
        st.insert(p);
        st.insert(q);
    }
    if(index==0) puts("misaka");
    else puts("ham");
    return 0;
}