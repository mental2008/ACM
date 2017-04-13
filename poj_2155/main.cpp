#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1010
using namespace std;

int C[maxn][maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int y, int d) {
    for(int i = x; i < maxn; i += lowbit(i)) {
        for(int j = y; j < maxn; j += lowbit(j)) {
            C[i][j] += d;
        }
    }
}

int sum(int x, int y) {
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        for(int j = y; j > 0; j -= lowbit(j)) {
            res += C[i][j];
        }
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(C, 0, sizeof(C));
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 0; i < q; i++) {
            getchar();
            char order;
            scanf("%c", &order);
            if(order == 'C') {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(x1, y1, 1);
                add(x1, y2 + 1, -1);
                add(x2 + 1, y1, -1);
                add(x2 + 1, y2 + 1, 1);
            }
            else {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%d\n", sum(x, y) % 2);
            }
        }
        printf("\n");
    }
    return 0;
}