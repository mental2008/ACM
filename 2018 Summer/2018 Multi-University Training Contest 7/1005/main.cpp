#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
ll phi[maxn];
ll mu[maxn];
ll prim[maxn];
bool vis[maxn];
ll f[maxn];
ll F[maxn];
ll inv[maxn];
int cnt;

void init() {
    for(int i = 2; i < maxn; ++i) phi[i] = 0;
    phi[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(!phi[i])
        for(int j = i; j < maxn; j += i) {
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    mu[1] = 1;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < maxn; ++i) {
        if(!vis[i]) {
            prim[++cnt] = i; mu[i] = -1;
        }
        for(int j = 1; j <= cnt && prim[j] * i < maxn; ++j) {
            vis[prim[j] * i] = 1;
            if(i % prim[j] == 0) break;
            else mu[i * prim[j]] = -mu[i];
        }
    }
}

int n, m;
ll p;

void solve() {
    int N = min(n, m);
    for(int i = 1; i <= N; ++i) F[i] = 1ll * (n / i) * (m / i);
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= N; ++i) {
        for(int j = i; j <= N; j += i) {
            f[i] = (f[i] + mu[j / i] * F[j]) % p;
        }
    }
    inv[1] = 1;
    for(int i = 2; i <= N; ++i) inv[i] = (1ll * (p - p / i) * inv[p % i]) % p;
    ll ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans = (ans + (inv[phi[i]] * i % p) * f[i] % p) % p;
    }
    printf("%lld\n", ans);
}

int main()
{
    init();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d%lld", &n, &m, &p);
        solve();
    }
    return 0;
}
