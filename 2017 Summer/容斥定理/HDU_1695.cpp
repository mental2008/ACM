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
const int maxn = 100005;
int a, b, c, d, k;
int Eular[maxn];
bool prime[maxn];
int p[maxn];
int fact[maxn];

LL solve(int last, LL LCM, int depth, int need) {
    if(depth < need && last == (int)fact[0]) return 0;
    if(depth == need) {
        return (LL)((double)b / LCM);
    }
    LL res = 0;
    for(int i = last + 1; i <= fact[0]; ++i) {
        res += solve(i, LCM * fact[i], depth + 1, need);
    }
    return res;
}

int main() {
    mem(Eular, 0);
    Eular[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(!Eular[i]) {
            for(int j = i; j < maxn; j += i) {
                if(!Eular[j]) Eular[j] = j;
                Eular[j] = Eular[j] / i * (i - 1);
            }
        }
    }
    mem(prime, 0);
    int num = 0;
    for(int i = 2; i < maxn; ++i) {
        if(!prime[i]) {
            p[num++] = i;
            for(int j = 2 * i; j < maxn; j += i) {
                prime[j] = 1;
            }
        }
    }
    int caseCnt;
    scanf("%d", &caseCnt);
    int times = 0;
    while(caseCnt--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("Case %d: ", ++times);
        if(k == 0) {
            puts("0");
            continue;
        }
        b /= k;
        d /= k;
        if(b == 0 || d == 0) {
            puts("0");
            continue;
        }
        if(b > d) swap(b, d);
        LL ans = 0;
        for(int i = 1; i <= b; ++i) {
            ans += Eular[i];
        }
        for(int i = b + 1; i <= d; ++i) {
            int temp = i;
            int cnt = 0;
            fact[0] = 0;
            for(int j = 0; p[j] <= temp / p[j]; ++j) {
                if(temp % p[j] == 0) {
                    fact[++cnt] = p[j];
                    fact[0]++;
                    while(temp % p[j] == 0) {
                        temp /= p[j];
                    }
                }
            }
            if(temp != 1) {
                fact[0]++;
                fact[++cnt] = temp;
            }
            LL res = b;
            for(int j = 1; j <= (int)fact[0]; ++j) {
                if(j % 2 == 0) res += solve(0, 1, 0, j);
                else res -= solve(0, 1, 0, j);
            }
            ans += res;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
