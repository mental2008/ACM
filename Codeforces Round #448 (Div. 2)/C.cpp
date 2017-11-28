#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const int maxn = 6e5 + 5;
int n;
int a[75];
int dp[75][maxn];
int f1[75];
int f0[75];
int mask[75];
vector<int> prime;

bool judge(int x) {
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}

void init() {
    prime.clear();
    for(int i = 2; i <= 70; ++i) {
        if(judge(i)) prime.push_back(i);
    }
    mem(mask, 0);
    for(int i = 2; i <= 70; ++i) {
        int temp = i;
        int len = prime.size();
        for(int j = 0; j < len && prime[j] <= temp; ++j) {
            if(temp % prime[j] == 0) {
                int num = 0;
                while(temp % prime[j] == 0) {
                    temp /= prime[j];
                    num++;
                }
                if(num & 1) mask[i] |= (1 << j);
            }

        }
    }
}

int quick_pow(int a, int n) {
    LL res = 1;
    LL p = a % MOD;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return (int)res;
}

int main() {
    init();
    // printf("%d\n", (int)prime.size());
    // printf("%d\n", (1 << 19));
    scanf("%d", &n);
    mem(a, 0);
    for(int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        a[val]++;
    }
    for(int i = 2; i <= 70; ++i) {
        if(a[i]) {
            f1[i] = quick_pow(2, a[i] - 1);
            f0[i] = quick_pow(2, a[i] - 1);
        }
        else {
            f1[i] = 0;
            f0[i] = 1;
        }
    }
    int len = prime.size();
    mem(dp, 0);
    dp[1][0] = quick_pow(2, a[1]);
    for(int i = 2; i <= 70; ++i) {
        for(int j = 0; j < (1 << len); ++j) {
            dp[i][j ^ mask[i]] = (1LL * dp[i][j ^ mask[i]] + 1LL * dp[i - 1][j] * f1[i] % MOD) % MOD;
            dp[i][j] = (1LL * dp[i][j] + 1LL * dp[i - 1][j] * f0[i] % MOD) % MOD;
        }
    }
    int ans = dp[70][0];
    ans--;
    ans = (ans % MOD + MOD) % MOD;
    printf("%d\n", ans);
    return 0;
}
