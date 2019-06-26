#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 36 + 5;
int n;
int p[maxn], a[maxn], c[maxn], m[maxn], g[maxn];
int P, A, C, M;
LL dp[maxn][maxn][maxn][maxn];
int sign[maxn][maxn][maxn][maxn];
LL ans;
int lef, rig;
vector<int> out;

int main()
{
    scanf("%d", &n);
    int mid = n / 2;
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d%d%d", &p[i], &a[i], &c[i], &m[i], &g[i]);
    }
    scanf("%d%d%d%d", &P, &A, &C, &M);
    memset(dp, 0, sizeof(dp));
    memset(sign, 0, sizeof(sign));
    for(int i = 0; i < (1 << (n - mid)); ++i) {
        int pp, aa, cc, mm, gg;
        pp = aa = cc = mm = gg = 0;
        for(int j = 0; j < (n - mid); ++j) {
            if((i >> j) & 1) {
                pp += p[j + mid];
                aa += a[j + mid];
                cc += c[j + mid];
                mm += m[j + mid];
                gg += g[j + mid];
            }
        }
        if(pp > P || aa > A || cc > C || mm > M) continue;
        // printf("%d %d %d %d %d\n", pp, aa, cc, mm, gg);
        if(dp[pp][aa][cc][mm] < gg) {
            dp[pp][aa][cc][mm] = gg;
            sign[pp][aa][cc][mm] = i;
        }
    }
    for(int i = 0; i <= P; ++i) {
        for(int j = 0; j <= A; ++j) {
            for(int k = 0; k <= C; ++k) {
                for(int l = 0; l <= M; ++l) {
                    if(i > 0 && dp[i - 1][j][k][l] > dp[i][j][k][l]) {
                        dp[i][j][k][l] = dp[i - 1][j][k][l];
                        sign[i][j][k][l] = sign[i - 1][j][k][l];
                    }
                    if(j > 0 && dp[i][j - 1][k][l] > dp[i][j][k][l]) {
                        dp[i][j][k][l] = dp[i][j - 1][k][l];
                        sign[i][j][k][l] = sign[i][j - 1][k][l];
                    }
                    if(k > 0 && dp[i][j][k - 1][l] > dp[i][j][k][l]) {
                        dp[i][j][k][l] = dp[i][j][k - 1][l];
                        sign[i][j][k][l] = sign[i][j][k - 1][l];
                    }
                    if(l > 0 && dp[i][j][k][l - 1] > dp[i][j][k][l]) {
                        dp[i][j][k][l] = dp[i][j][k][l - 1];
                        sign[i][j][k][l] = sign[i][j][k][l - 1];
                    }
                }
            }
        }
    }
    ans = 0;
    lef = rig = 0;
    for(int i = 0; i < (1 << mid); ++i) {
        int pp, aa, cc, mm, gg;
        pp = aa = cc = mm = gg = 0;
        for(int j = 0; j < mid; ++j) {
            if((i >> j) & 1) {
                pp += p[j];
                aa += a[j];
                cc += c[j];
                mm += m[j];
                gg += g[j];
            }
        }
        if(pp > P || aa > A || cc > C || mm > M) continue;
        if(dp[P - pp][A - aa][C - cc][M - mm] + gg > ans) {
            ans = dp[P - pp][A - aa][C - cc][M - mm] + gg;
            lef = i;
            rig = sign[P - pp][A - aa][C - cc][M - mm];
        }
    }
    out.clear();
    for(int i = 0; i < mid; ++i) {
        if((lef >> i) & 1) {
            out.push_back(i);
        }
    }
    for(int i = 0; i < (n - mid); ++i) {
        if((rig >> i) & 1) {
            out.push_back(i + mid);
        }
    }
    int len = (int)out.size();
    printf("%d\n", len);
    for(int i = 0; i < len; ++i) {
        printf("%d", out[i]);
        if(i != len - 1) printf(" ");
    }
    puts("");
    return 0;
}
