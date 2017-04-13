#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100100
#define LL long long 
using namespace std;

int C[maxn];
int D[maxn];
int a[maxn];
int num[maxn];

int lowbit(int x) {
    return x & (-x);
}

int add(int x, int d) {
    while(x < maxn) {
        num[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while(x > 0) {
        res += num[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++) {
            add(a[i], 1);
            C[i] = sum(a[i]) - 1;
        }
        memset(num, 0, sizeof(num));
        for(int i = n; i >= 1; i--) {
            add(a[i], 1);
            D[i] = sum(100000) - sum(a[i]);
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += ((1LL * C[i] * D[i]) + (1LL * (i - 1 - C[i]) * (n - i - D[i])));
        }
        printf("%lld\n", ans);
    }
    return 0;
}