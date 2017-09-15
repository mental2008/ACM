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
const LL INF = 1e18;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int MAX = 1e6 + 5;
const int maxn = 5e5 + 5;
bool prime[MAX];
vector<int> vec;
int n;
LL x, y;
int a[maxn];
LL sum[2 * MAX];
LL cnt[2 * MAX];

void init() {
    mem(prime, 0);
    vec.clear();
    for(int i = 2; i < MAX; ++i) {
        if(!prime[i]) {
            vec.push_back(i);
            for(int j = i * 2; j < MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    init();
    while(~scanf("%d", &n)) {
        scanf("%lld%lld", &x, &y);
        mem(sum, 0);
        mem(cnt, 0);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
            sum[a[i]] += a[i];
        }
        for(int i = 1; i < 2 * MAX; ++i) {
            sum[i] += sum[i - 1];
            cnt[i] += cnt[i - 1];
        }
        LL ans = INF;
        for(int i = 0; i < (int)vec.size(); ++i) {
            LL res = 0;
            for(int j = vec[i]; j < 2 * MAX; j += vec[i]) {
                if(res > ans) break;
                int temp = j - x / y - 1;
                if(temp < j - vec[i]) temp = j - vec[i];
                res += (cnt[temp] - cnt[j - vec[i]]) * x;
                res += ((cnt[j] - cnt[temp]) * j - (sum[j] - sum[temp])) * y;
            }
            if(ans > res) ans = res;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
