#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100100
using namespace std;

int C[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int d) {
    while(x < maxn) {
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
    int n;
    while(scanf("%d", &n) && n) {
        memset(C, 0, sizeof(C));
        for(int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, 1);
            add(b + 1, -1);
        }
        for(int i = 1; i <= n; i++) {
            if(i != 1) printf(" ");
            printf("%d", sum(i));
        }
        printf("\n");
    }
    return 0;
}