#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e7 + 5;
bool vis[maxn];
int mu[maxn];
int prime[maxn];
int cnt;

void Mobius() {
    int n = maxn;
    mem(prime, 0);
    mem(mu, 0);
    mem(vis, 0);
    mu[1] = 1;
    cnt = 0;
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
    int n;
    scanf("%d", &n);
    Mobius();
    LL ans = 0;
    for(int i = 0; i < cnt && prime[i] <= n; ++i) {
        int temp = n / prime[i];
        for(int j = 1; j <= temp; ++j) {
            ans += (1LL * mu[j] * (temp / j) * (temp / j));
        }
    }
    printf("%lld\n", ans);
    return 0;
}
