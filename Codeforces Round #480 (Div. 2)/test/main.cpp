#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char ch[4][maxn];
int dp1[4][maxn];
int dp2[4][maxn];

int main()
{
    for(int i = 0; i < 4; ++i) {
        scanf("%s", ch[i]);
    }
    int n = strlen(ch[0]);
    memset(dp1, 0, sizeof(dp1));
    dp1[0][0] = 1;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0 && j == 0) continue;
            if(ch[i][j] == '#') continue;
            if(i >= 1) dp1[i][j] += dp1[i - 1][j];
            if(j >= 1) dp1[i][j] += dp1[i][j - 1];
        }
    }
    memset(dp2, 0, sizeof(dp2));
    dp2[3][0] = 1;
    for(int i = 3; i >= 0; --i) {
        for(int j = 0; j < n; ++j) {
            if(i == 3 && j == 0) continue;
            if(ch[i][j] == '#') continue;
            if(i <= 2) dp2[i][j] += dp2[i + 1][j];
            if(j >= 1) dp2[i][j] += dp2[i][j - 1];
        }
    }
    cout << dp1[3][n - 1] << ' ' << dp2[0][n - 1] << '\n';
    return 0;
}
