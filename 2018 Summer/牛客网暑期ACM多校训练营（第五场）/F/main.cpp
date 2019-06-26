#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long LL;
const int maxn = 1e5 + 5;
const int MOD = 998244353;
int n;
LL p[maxn];
LL d[maxn];
map<LL, int> mp;
set<LL> st;
int tot;
LL Tree[maxn];

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        LL r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

LL inv(LL a) {
    LL x, y;
    extend_gcd(a, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

inline int lowbit(int x) {
    return (x & -x);
}

void add(int x, LL value) {
    for(int i = x; i <= tot; i += lowbit(i))
        Tree[i] = (Tree[i] * value) % MOD;
}

LL get(int x) {
    LL sum = 1;
    for(int i = x; i; i -= lowbit(i))
        sum = (sum * Tree[i]) % MOD;
    return sum;
}

int main()
{
    while(~scanf("%d", &n)) {
        st.clear();
        mp.clear();
        rep(i, 1, n) {
            scanf("%lld%lld", &p[i], &d[i]);
            st.insert(d[i]);
        }
        tot = 0;
        for(auto x : st) {
            mp[x] = ++tot;
        }
        rep(i, 1, tot) Tree[i] = 1;
        LL ans = 0;
        LL MAX = 0;
        rep(i, 1, n) {
            int index = mp[d[i]];
            LL temp = (get(tot) * inv(get(index - 1))) % MOD;
            temp = (temp * p[i] % MOD) * inv(100LL) % MOD;
            if(d[i] <= MAX) continue;
            if(p[i] == 100) {
                MAX = max(MAX, d[i]);
                p[i] = 0;
            }
            ans = (ans + temp) % MOD;
            add(index, ((100LL - p[i]) * inv(100LL)) % MOD);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
