#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 100005;
int b, n, e;
int sb, sn, se;
int c[maxn];
int sum;

bool judge(int x) {
    int tb = b, tn = n, te = e;
    for(int i = 1; i <= sum; ++i) {
        if(tb >= 2 && c[i] * 2 * sb >= x) tb -= 2;
        else if(tb >= 1 && tn >= 1 && c[i] * (sb + sn) >= x) tb--, tn--;
        else if(2 * sn <= sb + se) {
            if(tn >= 2 && c[i] * 2 * sn >= x) tn -= 2;
            else if(tb >= 1 && te >= 1 && c[i] * (sb + se) >= x) tb--, te--;
            else if(tn >= 1 && te >= 1 && c[i] * (sn + se) >= x) tn--, te--;
            else if(te >= 2 && c[i] * 2 * se >= x) te -= 2;
            else return false;
        }
        else {
            if(tb >= 1 && te >= 1 && c[i] * (sb + se) >= x) tb--, te--;
            else if(tn >= 2 && c[i] * 2 * sn >= x) tn -= 2;
            else if(tn >= 1 && te >= 1 && c[i] * (sn + se) >= x) tn--, te--;
            else if(te >= 2 && c[i] * 2 * se >= x) te -= 2;
            else return false;
        }
    }
    return true;
}

int main() {
    while(~scanf("%d%d%d", &b, &n, &e)) {
        scanf("%d%d%d", &sb, &sn, &se);
        sum = (b + n + e) / 2;
        for(int i = 1; i <= sum; ++i) {
            scanf("%d", &c[i]);
        }
        int l = 0, r = 2e8 + 5;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(judge(mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
