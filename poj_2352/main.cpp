#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 32000
using namespace std;

int level[maxn + 10];
int C[maxn + 10];
int n;

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int d) {
    while(x <= maxn + 1) {
        C[x] += d;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while(x > 0) {
        res += C[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    while(~scanf("%d", &n)) {
        memset(level, 0, sizeof(level));
        memset(C, 0, sizeof(C));
        for(int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x++;
            level[sum(x)]++;
            add(x, 1);
        }
        for(int i = 0; i < n; i++) {
            printf("%d\n", level[i]);
        }
    }
    return 0;
}