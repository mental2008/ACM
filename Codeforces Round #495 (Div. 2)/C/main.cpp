#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
int MIN[maxn];
int MAX[maxn];
vector<int> vec;

int main()
{
    scanf("%d", &n);
    int p = INF, q = -1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        p = min(p, a[i]);
        q = max(q, a[i]);
    }
    for(int i = p; i <= q; ++i) {
        MIN[i] = INF;
        MAX[i] = -1;
    }
    for(int i = 1; i <= n; ++i) {
        MIN[a[i]] = min(MIN[a[i]], i);
        MAX[a[i]] = max(MAX[a[i]], i);
    }
    vec.clear();
    for(int i = p; i <= q; ++i) {
        if(MIN[i] == INF || MAX[i] == -1) continue;
        vec.push_back(MIN[i]);
    }
    sort(vec.begin(), vec.end());
    LL sum = 0;
    for(int i = p; i <= q; ++i) {
        if(MAX[i] == INF || MAX[i] == -1) continue;
        int len = vec.size();
        int l = 0, r = len - 1;
        LL ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(vec[mid] < MAX[i]) {
                ans = mid + 1;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        sum += ans;
    }
    printf("%lld\n", sum);
    return 0;
}
