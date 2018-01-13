#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int fa[maxn];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool connect(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x == y) return false;
    else {
        fa[x] = y;
        // printf("%d %d\n", a, b);
        return true;
    }
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        init(n);
        int turn = 0;
        LL ans = 0;
        for(int i = 0; i <= n; ++i) {
            if(turn == n - 1) break;
            for(int j = 1; j <= n; ++j) {
                if(i - j > j) {
                    if(connect(i - j, j)) {
                        turn++;
                        ans += i;
                    }
                }
                if(turn == n - 1) break;
                if((n + 1 + i - j > n) || (n + 1 + i - j <= j)) continue;
                if(connect(n + 1 + i - j, j)) {
                    turn++;
                    ans += i;
                }
                if(turn == n - 1) break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
