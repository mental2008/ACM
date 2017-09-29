#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
typedef long long LL;
using namespace std;
const int maxn = 1000005;
int prime[maxn];
int cnt;
bool vis[maxn];
int mu[maxn];

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
}

int main() {
    Mobius();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n;
        scanf("%d", &n);
        LL ans = 3;
        for(int i = 1; i <= n; ++i) {
            ans += (1LL * mu[i] * (n / i) * (n / i) * (n / i));
        }
        for(int i = 1; i <= n; ++i) {
            ans += (3LL * mu[i] * (n / i) * (n / i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
