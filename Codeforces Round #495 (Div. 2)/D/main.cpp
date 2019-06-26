#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e6 + 5;
int cnt[maxn];
int vis[maxn];

void output() {
    printf("1000000\n");
    for(int i = 1; i <= 500; ++i) {
        for(int j = 1; j <= 2000; ++j) {
            printf("%d ", abs(i - 184) + abs(j - 51));
        }
    }
}
int MAX;

bool check(int n, int m, int x, int y) {
    mem(vis, 0);
    for(int j = 0; j <= MAX; ++j) {
        vis[j] = cnt[j];
    }
    for(int j = 1; j <= n; ++j) {
        for(int k = 1; k <= m; ++k) {
            vis[abs(j - x) + abs(k - y)]--;
            if(vis[abs(j - x) + abs(k - y)] < 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // freopen("a.in", "r", stdin);
    // output();
    int t;
    scanf("%d", &t);
    MAX = -1;
    for(int i = 1; i <= t; ++i) {
        int val;
        scanf("%d", &val);
        cnt[val]++;
        MAX = max(MAX, val);
    }
    if(t == 1) {
        if(cnt[0] == 1) printf("1 1\n1 1\n");
        else puts("-1");
        return 0;
    }
    int x;
    for(int i = 1; i <= MAX; ++i) {
        if(4 * i != cnt[i]) {
            x = i;
            break;
        }
    }
    for(int n = 1; n * n <= t; ++n) {
        if(t % n == 0) {
            int m = t / n;
            int a = n + m - 2 - MAX;
            int y = a - x + 2;
            if(check(n, m, x, y)) {
                printf("%d %d\n%d %d\n", n, m, x, y);
                return 0;
            }
            if(check(m, n, x, y)) {
                printf("%d %d\n%d %d\n", m, n, x, y);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
