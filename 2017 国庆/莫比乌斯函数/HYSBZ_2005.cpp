#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
typedef long long LL;
using namespace std;
const int maxn = 100005;
int prime[maxn];
int cnt;
bool vis[maxn];
int mu[maxn];
LL sum[maxn];

void Mobius() {
    mem(prime, 0);
    mem(vis, 0);
    mem(mu, 0);
    mu[1] = 1;
    cnt = 0;
    int n = maxn;
    for(int i = 2; i < n; ++i) {
        if(!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < cnt && i * prime[j] < n; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    mem(sum, 0);
    for(int i = 1; i < n; ++i) {
        for(int j = i; j < n; j += i) {
            sum[j] += (mu[i] * (j / i));
        }
    }
}

int main() {
    Mobius();
    LL n, m;
    while(~scanf("%lld%lld", &n, &m)) {
        LL res = min(n, m);
        LL ans = 0;
        for(int i = 1; i <= (int)res; ++i) {
            ans += (2LL * (n / i) * (m / i) * sum[i]);
        }
        ans -= (n * m);
        printf("%lld\n", ans);
    }
    return 0;
}
