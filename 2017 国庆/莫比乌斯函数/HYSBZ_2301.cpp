#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 50005;
int prime[maxn];
bool vis[maxn];
int cnt;
int mu[maxn];
int pre[maxn];

void Mobius() {
    int n = maxn;
    mem(prime, 0);
    mem(vis, 0);
    mem(mu, 0);
    mem(pre, 0);
    pre[1] = 1;
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
        pre[i] = pre[i - 1] + mu[i];
    }
}

LL cal(int n, int m) {
    int res = min(n, m);
    LL sum = 0;
    int end;
    for(int i = 1; i <= res; i = end + 1) {
        end = min(n / (n / i), m / (m / i));
        sum += (1LL * (pre[end] - pre[i - 1]) * (n / i) * (m / i));
    }
    return sum;
}

int main() {
    Mobius();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        LL ans = cal(b / k, d / k) - cal((a - 1) / k, d / k) - cal(b / k, (c - 1) / k) + cal((a - 1) / k, (c - 1) / k);
        printf("%lld\n", ans);
    }
    return 0;
}
