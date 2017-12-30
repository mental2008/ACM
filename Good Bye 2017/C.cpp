#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const int maxn = 1005;
int n, r;
struct Node {
    double x, y;
} node[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &n, &r)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lf", &node[i].x);
        }
        for(int i = 1; i <= n; ++i) {
            node[i].y = r;
            for(int j = i - 1; j >= 1; --j) {
                if(fabs(node[i].x - node[j].x) - 2 * r < exps) {
                    double temp = sqrt(2 * r * 2 * r - fabs(node[i].x - node[j].x) * fabs(node[i].x - node[j].x));
                    node[i].y = max(node[i].y, temp + node[j].y);
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            printf("%.6lf%c", node[i].y, (i == n ? '\n' : ' '));
        }
    }
    return 0;
}
