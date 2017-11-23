#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const LL INF = 0x3f3f3f3f;
int n;
LL d;
LL a[maxn];
LL sum[maxn];
vector<int> vec;
vector<LL> upp;

bool judge() {
    LL balance = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 0) {
            if(balance < 0) {
                balance = 0;
            }
        }
        else {
            balance += a[i];
            if(balance > d) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    if(judge()) {
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
        vec.clear();
        upp.clear();
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) vec.push_back(i);
        }
        int len0 = vec.size();
        for(int i = 0; i < len0 - 1; ++i) {
            LL temp = 0;
            LL uppn = -INF;
            for(int j = vec[i]; j <= vec[i + 1]; ++j) {
                temp = a[j] + temp;
                uppn = max(uppn, temp);
            }
            upp.push_back(uppn);
        }
        int start = -1;
        for(int i = 0; i < len0; ++i) {
            if(sum[vec[i]] < 0) {
                start = i;
                break;
            }
        }
        if(start == -1) puts("0");
        else {
            int ans = 0;
            for(int i = start; i < len0; ++i) {
                if(i == len0 - 1) {
                    ans++;
                    continue;
                }
                LL l = sum[vec[i]] - sum[vec[i + 1]];
                LL r = d - upp[i];
                // printf("%lld %lld\n", l, r);
                if(l > r) {
                    ans++;
                    continue;
                }
                bool ok = true;
                for(int j = i + 1; j < len0; ++j) {
                    LL newl = sum[vec[i]] - sum[vec[j]];
                    LL newr = d - upp[j - 1];
                    // printf("%lld %lld\n", newl, newr);
                    // printf("%d\n", j);
                    l = max(l, newl);
                    r = min(r, newr);
                    if(newr < newl) {
                        // puts("done");
                        ans++;
                        i = j - 1;
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    ans++;
                    break;
                }
            }
            printf("%d\n", ans);
        }

    }
    else puts("-1");
    return 0;
}
