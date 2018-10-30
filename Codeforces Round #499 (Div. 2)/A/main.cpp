#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, k;
char s[maxn];
int dp[maxn][maxn];

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    sort(s, s + n);
    int last = 'a' - 2;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] - last >= 2) {
            ans += (s[i] - 'a' + 1);
            last = s[i];
            cnt++;
            if(cnt == k) break;
        }
    }
    if(cnt == k)
        printf("%d\n", ans);
    else
        puts("-1");
    return 0;
}
