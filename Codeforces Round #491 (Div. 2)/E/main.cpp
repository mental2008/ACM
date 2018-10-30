#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL cnt[12];
LL ans = 0;
LL A[21];
LL C[21][21];
LL temp[12];

void dfs(int depth, LL len) {
    if(depth == 10) {
        LL res = A[len];
        for(int i = 1; i <= 9; ++i) {
            res /= A[temp[i]];
        }
        if(cnt[0] == 0) {
            ans += res;
        }
        else {
            for(int i = 1; i <= cnt[0]; ++i) {
                //if(len == 1) {
                //    ans += res;
                //}
                //else {
                    ans += res * C[i + len - 1][len - 1];
                //}
            }
        }
        return;
    }
    if(cnt[depth] == 0) {
        dfs(depth + 1, len);
    }
    else {
        for(int i = 1; i <= cnt[depth]; ++i) {
            temp[depth] += i;
            dfs(depth + 1, len + i);
            temp[depth] -= i;
        }
    }
}

int main()
{
    memset(cnt, 0, sizeof(cnt));
    A[0] = 1;
    for(int i = 1; i <= 20; ++i) {
        A[i] = i * A[i - 1];
    }
    memset(C, 0, sizeof(C));
    for(int i = 1; i <= 20; ++i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    scanf("%lld", &n);
    while(n) {
        cnt[n % 10]++;
        n /= 10;
    }
    ans = 0;
    memset(temp, 0, sizeof(temp));
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
