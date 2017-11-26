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
LL suffix[maxn];

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

        //new method
        suffix[n] = sum[n];
        for(int i = n - 1; i >= 1; --i) {
            suffix[i] = max(suffix[i + 1], sum[i]);
        }
        LL balance = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) {
                if(balance + sum[i] < 0) {
                    balance += (d - (suffix[i] + balance));
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        // vec.clear();
        // upp.clear();
        // for(int i = 1; i <= n; ++i) {
        //     if(a[i] == 0) vec.push_back(i);
        // }
        // int len0 = vec.size();
        // for(int i = 0; i < len0 - 1; ++i) {
        //     LL temp = 0;
        //     LL uppn = -INF;
        //     for(int j = vec[i]; j <= vec[i + 1]; ++j) {
        //         temp = a[j] + temp;
        //         uppn = max(uppn, temp);
        //     }
        //     upp.push_back(uppn);
        // }
        // int start = -1;
        // for(int i = 0; i < len0; ++i) {
        //     if(sum[vec[i]] < 0) {
        //         start = i;
        //         break;
        //     }
        // }
        // if(start == -1) puts("0");
        // else {
        //     int ans = 0;
        //     for(int i = start; i < len0; ++i) {
        //         if(i == len0 - 1) {
        //             ans++;
        //             continue;
        //         }
        //         // LL l = sum[vec[i]] - sum[vec[i + 1]];
        //         LL l, r;
        //         if(i == start) {
        //             l = max(-sum[vec[i]], -sum[vec[i + 1]]);
        //             r = d - upp[i] - sum[vec[i]];
        //         }
        //         else {
        //             l = max(sum[vec[i - 1]] - sum[vec[i]], sum[vec[i - 1]] - sum[vec[i + 1]]);
        //             r = d - upp[i] - sum[vec[i]] + sum[vec[i - 1]];
        //         }
        //         // if(i == start) l = max(-sum[vec[i]], l);
        //         // else l = max(sum[vec[i - 1]] - sum[vec[i]], l);
        //         // LL r = d - upp[i];
        //         // printf("%lld %lld\n", l, r);
        //         if(l > r) {
        //             ans++;
        //             continue;
        //         }
        //         bool ok = true;
        //         for(int j = i + 2; j < len0; ++j) {
        //             if(i == start) {
        //                 l = l + sum[vec[j - 1]];
        //                 r = r + sum[vec[j - 1]];
        //             }
        //             else {
        //                 l = l + sum[vec[j - 1]] - sum[vec[i]];
        //                 r = r + sum[vec[j - 1]] - sum[vec[i]];
        //             }
        //             l = max(l, sum[vec[j - 1]] - sum[vec[j]]);
        //             r = min(r, d - upp[j - 1]);
        //             if(r < l) {
        //                 // puts("done");
        //                 ans++;
        //                 i = j - 1;
        //                 ok = false;
        //                 break;
        //             }
        //         }
        //         if(ok) {
        //             ans++;
        //             break;
        //         }
        //     }
        //     printf("%d\n", ans);
        // }
    }
    else puts("-1");
    return 0;
}
