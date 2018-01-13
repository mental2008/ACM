#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
const int maxn = 1e5 + 5;
LL pos[maxn];
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n, m;
        LL p;
        scanf("%d%d%lld", &n, &m, &p);
        int left = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &pos[i]);
            if(pos[i] <= p) {
                left = i;
            }
        }
        LL ans = INF;
        if(left == 0) {
            for(int i = 1; i < n; ++i) {
                LL temp = pos[i] - p;
                if(i <= m) temp += ((m - i) * (pos[i + 1] - pos[i]));
                ans = min(ans, temp);
            }
        }
        else {
            for(int i = 1; i < n; ++i) {
                if(i + 1 <= left) {
                    LL temp = p - pos[i + 1];
                    int num = left - (i + 1) + 1;
                    if(num < m) temp += ((m - num) * (pos[i + 1] - pos[i]));
                    ans = min(ans, temp);
                    if(left < n) {
                        temp = pos[left + 1] - pos[i + 1] + pos[left + 1] - p;
                        num = left + 1 - (i + 1) + 1;
                        if(num < m) temp += ((m - num) * (pos[i + 1] - pos[i]));
                        ans = min(ans, temp);
                    }
                }
                else if(i > left){
                    LL temp = pos[i] - p;
                    int num = i - (left + 1) + 1;
                    if(num < m) temp += ((m - num) * (pos[i + 1] - pos[i]));
                    ans = min(ans, temp);
                    temp = pos[i] - pos[left] + p - pos[left];
                    num = i - left + 1;
                    if(num < m) temp += ((m - num) * (pos[i + 1] - pos[i]));
                    ans = min(ans, temp);
                }
                else {
                    LL temp = min(p - pos[i], pos[i + 1] - p);
                    temp += ((m - 1) * (pos[i + 1] - pos[i]));
                    ans = min(ans, temp);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
