#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int x, y;
vector<int> vec;

LL quick_pow(LL a, int n) {
    LL res = 1;
    LL p = a % MOD;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &x, &y);
    if(y % x != 0) {
        puts("0");
    }
    else {
        int m = y / x;
        vec.clear();
        int tmp = m;
        for(int i = 2; i * i <= tmp; ++i) {
            if(tmp % i == 0) {
                vec.push_back(i);
                while(tmp % i == 0) tmp /= i;
            }
        }
        if(tmp != 1) vec.push_back(tmp);
        LL ans = quick_pow(2LL, m - 1);
        int len = vec.size();
        // for(int i = 0; i < len; ++i) {
        //     LL temp = quick_pow(2LL, m / vec[i] - 1) - 1;
        //     temp = (temp % MOD + MOD) % MOD;
        //     ans = (ans - temp) % MOD;
        //     ans = (ans % MOD + MOD) % MOD;
        // }
        for(int i = 1; i < (1 << len); ++i) {
            int cnt = 0;
            LL temp = 1;
            for(int j = 0; j < len; ++j) {
                if((i >> j) & 1) {
                    cnt++;
                    temp *= vec[j];
                    if(temp > m) break;
                }
            }
            if(temp > m) continue;
            LL k = quick_pow(2LL, m / temp - 1);
            int sign;
            if(cnt % 2 == 0) sign = 1;
            else sign = -1;
            ans = (ans + sign * k) % MOD;
            ans = (ans % MOD + MOD) % MOD;
        }
        // if(m != 1) ans = (ans - 1) % MOD;
        ans = (ans % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
