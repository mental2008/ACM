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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 50005;
int L, W;
int n;
struct Node {
    double l, r;
    bool operator < (const Node& e) const {
        return l < e.l;
    }
} node[maxn];
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &L, &W)) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            double x, radius;
            scanf("%lf%lf", &x, &radius);
            if(radius < W / 2.0) {
                i--;
                n--;
                continue;
            }
            double temp = sqrt(radius * radius - W / 2.0 * W / 2.0);
            node[i].l = max((double)0, x - temp);
            node[i].r = min((double)L, x + temp);
        }
        sort(node, node + n);
        double pos = 0;
        int k = -1;
        int cnt = 0;
        while(pos < L && node[k + 1].l <= pos) {
            double MAX = -1;
            for(int i = k + 1; node[i].l <= pos && i < n; ++i) {
                if(MAX < node[i].r) {
                    MAX = node[i].r;
                    k = i;
                }
            }
            pos = MAX;
            cnt++;
        }
        if(fabs(L - pos) < exps) printf("%d\n", cnt);
        else puts("-1");
    }
    return 0;
}
