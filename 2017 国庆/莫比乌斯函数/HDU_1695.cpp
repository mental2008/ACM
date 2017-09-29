#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
typedef long long LL;
using namespace std;
const int maxn = 100005;
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
    for(int times = 1; times <= caseCnt; ++times) {
        int a, b;
        int c, d;
        int k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if(k == 0) {
            printf("Case %d: %lld\n", times, 0LL);
            continue;
        }
        if(b > d) swap(b, d);
        LL ans1 = 0;
        for(int i = 1; i * k <= b; ++i) {
            ans1 += (1LL * mu[i] * (b / (i * k)) * (d / (i * k)));
        }
        LL ans2 = 0;
        for(int i = 1; i * k <= b; ++i) {
            ans2 += (1LL * mu[i] * (b / (i * k)) * (b / (i * k)));
        }
        printf("Case %d: %lld\n", times, ans1 - ans2 / 2);
    }
    return 0;
}
