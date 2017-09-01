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
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
vector<int> vec;
bool prime[355];
LL dp[355][355];
int main() {
    mem(prime, 0);
    vec.clear();
    for(int i = 2; i <= 350; ++i) {
        if(!prime[i]) {
            vec.push_back(i);
            for(int j = 2 * i; j <= 350; j += i) {
                prime[j] = 1;
            }
        }
    }
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            
        }
    }
    return 0;
}
