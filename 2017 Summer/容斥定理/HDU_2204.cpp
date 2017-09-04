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
LL n;
vector<int> vec;
bool prime[65];

int main() {
    vec.clear();
    mem(prime, 0);
    for(int i = 2; i <= 60; ++i) {
        if(!prime[i]) {
            vec.push_back(i);
            for(int j = 2 * i; j <= 60; j += i) {
                prime[j] = 1;
            }
        }
    }
    while(~scanf("%lld", &n)) {
        int len = (int)vec.size();
        LL ans = 1;
        for(int i = 0; i < len; ++i) {
            LL temp = (LL)pow(n, 1.0 / vec[i]);
            ans += (temp - 1);
        }
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                LL temp = (LL)pow(n, 1.0 / (vec[i] * vec[j]));
                ans -= (temp - 1);
            }
        }
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                for(int k = j + 1; k < len; ++k) {
                    LL temp = (LL)pow(n, 1.0 / (vec[i] * vec[j] * vec[k]));
                    ans += (temp - 1);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
