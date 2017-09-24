#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 1005;
int N;
struct Point
{
    LL x, y;
    int index;
    inline Point operator- (const Point &t)
    {
        Point ret;
        ret.x = x - t.x;
        ret.y = y - t.y;
        return ret;
    }
    inline Point operator+ (const Point &t)
    {
        Point ret;
        ret.x = x + t.x;
        ret.y = y + t.y;
        return ret;
    }
    inline LL det(const Point &t)
    {
        return x * t.y - t.x * y;
    }
} d[MAXN];
bool cmp(const Point &a, const Point &b)
{
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int convex[MAXN], cTotal;
void get_convex_hull()
{
    sort(d, d + N, cmp);
    int Total = 0, tmp;
    for (int i = 0; i < N; ++i)
    {
        while ( (Total > 1) &&
                ((d[convex[Total - 1]] - d[convex[Total - 2]]).det(
                d[i] - d[convex[Total - 1]]) <= 0) ) Total--;
        convex[Total++] = i;
    }
    tmp = Total;
    for (int i = N - 2 ; i >= 0 ; --i)
    {
        while ( (Total > tmp) &&
                ((d[convex[Total - 1]] - d[convex[Total - 2]]).det(
                d[i] - d[convex[Total - 1]]) <= 0) ) Total--;
        convex[Total++] = i;
    }
    cTotal = Total;
}
char ans[MAXN];
bool vis[MAXN];
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%lld%lld", &d[i].x, &d[i].y);
            d[i].index = i;
        }
        if(N == 1 || N == 2) {
            puts("NO");
            continue;
        }
        get_convex_hull();
        mem(vis, 0);
        if(N == 3 && cTotal - 1 == 3) {
            puts("NO");
            continue;
        }
        // for(int i = 0; i < cTotal - 1; ++i) {
        //     printf("%d\n", convex[i]);
        // }
        if(cTotal - 1 != N) {
            for(int i = 0; i < cTotal - 1; ++i) {
                ans[d[convex[i]].index] = 'A';
                vis[d[convex[i]].index] = 1;
            }
            for(int i = 0; i < N; ++i) {
                if(!vis[i]) {
                    ans[i] = 'B';
                }
            }
        }
        else {
            for(int i = 0; i < cTotal - 1; ++i) {
                ans[d[convex[i]].index] = 'A';
                vis[d[convex[i]].index] = 1;
            }
            ans[d[convex[0]].index] = 'B';
            ans[d[convex[2]].index] = 'B';
        }
        puts("YES");
        for(int i = 0; i < N; ++i) {
            printf("%c", ans[i]);
        }
        puts("");
    }
    return 0;
}
