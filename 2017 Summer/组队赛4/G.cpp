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
#include <ctime>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e5 + 5;
int n;
LL a[maxn];
LL pre[maxn];
LL done[maxn][30];
LL res[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        pre[0] = 0;
        for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] ^ a[i];
        LL ans = 0;
        mem(done, 0);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 30; ++j) {
                done[i][j] = done[i - 1][j];
            }
            LL temp = pre[i];
            int cnt = 0;
            while(temp) {
                if(temp & 1) done[i][cnt]++;
                temp >>= 1;
                cnt++;
            }
        }
        // printf("%lld\n\n", done[2][1]);
        mem(res, 0);
        for(int i = 1; i <= n; ++i) {
            ans += pre[i];
            if(i > 1) {
                LL tempp = 0;
                LL temp = pre[i];
                int cnt = 0;
                // puts("");
                while(1) {
                    if(cnt == 30) break;
                    if(temp & 1) res[cnt] = (i - 1 - done[i - 1][cnt]);
                    else res[cnt] = (done[i - 1][cnt]);
                    // printf("cnt = %d, res[cnt] = %lld\n", cnt, res[cnt]);
                    temp >>= 1;
                    cnt++;
                }
                LL board = 1;
                for(int j = 0; j < cnt; ++j) {
                    tempp += board * res[j];
                    board *= 2;
                }
                ans += tempp;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
