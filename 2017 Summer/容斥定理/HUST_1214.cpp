#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
LL L, R;
bool prime[2005];
vector<int> vec;

void init() {
    vec.clear();
    mem(prime, 0);
    for(int i = 2; i < 2005; ++i) {
        if(!prime[i]) {
            vec.push_back(i);
            for(int j = i * 2; j < 2005; j += i) {
                prime[j] = 1;
            }
        }
    }
}

LL dfs(int depth, int need, int last, LL sum, LL n) {
    if(sum * sum * sum > n) return 0;
    if(last == (int)vec.size() - 1 && depth < need) return 0;
    if(depth == need) {
        return n / (sum * sum * sum);
    }
    LL res = 0;
    for(int i = last + 1; i < (int)vec.size(); ++i) {
        res += dfs(depth + 1, need, i, sum * vec[i], n);
    }
    return res;
}

LL cal(LL n) {
    LL ans = 0;
    for(int i = 1; ; ++i) {
        LL temp = dfs(0, i, -1, 1, n);
        if(temp == 0) break;
        if(i & 1 == 0) ans -= temp;
        else ans += temp;
    }
    return n - ans;
}

int main() {
    init();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", cal(R - 1) - cal(L - 1));
    }
    return 0;
}
