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
struct Node {
    LL x, y;
    bool operator == (const Node& e) const {
        if(x == e.x && y == e.y) return true;
        else return false;
    }
} node[3];

LL calArea(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
    return abs(x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);
}

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

LL solve(LL x1, LL y1, LL x2, LL y2) {
    if(x1 == x2) {
        return max(0LL, abs(y1 - y2) - 1);
    }
    else if(y1 == y2) {
        return max(0LL, abs(x1 - x2) - 1);
    }
    else {
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        LL A = abs(y2 - y1);
        LL B = abs(x2 - x1);
        LL GCD = gcd(A, B);
        A /= GCD;
        B /= GCD;
        if(B == 1) return x2 - x1 - 1;
        else return max(0LL, (x2 - x1) / B - 1);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        for(int i = 0; i < 3; ++i) {
            scanf("%lld%lld", &node[i].x, &node[i].y);
        }
        if(node[0] == node[1] && node[1] == node[2]) {
            puts("1");
        }
        else if(node[0] == node[1]) {
            LL sum = solve(node[0].x, node[0].y, node[2].x, node[2].y) + 2;
            printf("%lld\n", sum);
        }
        else if(node[1] == node[2]) {
            LL sum = solve(node[0].x, node[0].y, node[1].x, node[1].y) + 2;
            printf("%lld\n", sum);
        }
        else if(node[0] == node[2]) {
            LL sum = solve(node[0].x, node[0].y, node[1].x, node[1].y) + 2;
            printf("%lld\n", sum);
        }
        else {
            LL S = calArea(node[0].x, node[0].y, node[1].x, node[1].y, node[2].x, node[2].y);
            LL a = solve(node[0].x, node[0].y, node[1].x, node[1].y);
            LL b = solve(node[0].x, node[0].y, node[2].x, node[2].y);
            LL c = solve(node[1].x, node[1].y, node[2].x, node[2].y);
            LL sum = 3 + a + b + c;
            LL ans = (S + 2 + sum) / 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
