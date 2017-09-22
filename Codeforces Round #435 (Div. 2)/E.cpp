#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100005;
int n, m, q;
LL a[maxn];
LL b[maxn];
LL sum1[maxn];
LL sum2[maxn];
vector<LL> vec;//LL啊啊啊啊啊

LL solve(LL num) {
    int len = (int)vec.size();
    int l = 0, r = len - 1;
    LL diff = INF;
    while(l <= r) {
        int mid = (l + r) / 2;
        diff = min(diff, abs(vec[mid] - num));
        if(vec[mid] == num) {
            l = mid;
            break;
        }
        else if(vec[mid] < num) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return diff;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    LL res = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if(i & 1) res += a[i];
        else res -= a[i];
    }
    sum1[0] = sum2[0] = 0;
    for(int i = 1; i <= m; ++i) {
        scanf("%lld", &b[i]);
        if(i & 1) {
            sum1[i] = sum1[i - 1] + b[i];
            sum2[i] = sum2[i - 1] - b[i];
        }
        else {
            sum1[i] = sum1[i - 1] - b[i];
            sum2[i] = sum2[i - 1] + b[i];
        }
    }
    vec.clear();
    for(int i = m; i >= n; --i) {
        if((i - n + 1) & 1) {
            vec.push_back(sum2[i] - sum2[i - n]);
        }
        else {
            vec.push_back(sum1[i] - sum1[i - n]);
        }
    }
    sort(vec.begin(), vec.end());
    LL ans = solve(-res);
    printf("%lld\n", ans);
    while(q--) {
        int l, r;
        LL x;
        scanf("%d%d%lld", &l, &r, &x);
        if((r - l + 1) & 1) {
            if(l & 1) res += x;
            else res -= x;
            ans = solve(-res);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
