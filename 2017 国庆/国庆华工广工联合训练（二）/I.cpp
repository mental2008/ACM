#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1005;
int n;
LL k;
struct Node {
    LL x, m;
} pp[maxn], np[maxn];
int pn;
int nn;

bool cmp1(Node a, Node b) {
    return a.x > b.x;
}

bool cmp2(Node a, Node b) {
    return a.x < b.x;
}

int main() {
    while(~scanf("%d%lld", &n, &k)) {
        pn = nn = 0;
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            LL x, w;
            scanf("%lld%lld", &x, &w);
            if(x == 0) continue;
            else if(x > 0) {
                pp[pn].x = x;
                pp[pn++].m = w;
            }
            else {
                np[nn].x = x;
                np[nn++].m = w;
            }
        }
        sort(pp, pp + pn, cmp1);
        sort(np, np + nn, cmp2);
        for(int i = 0; i < pn; ++i) {
            if(pp[i].m > k) {
                LL temp = pp[i].m / k;
                pp[i].m = pp[i].m % k;
                ans += (temp * pp[i].x * 2);
                i--;
                continue;
            }
            if(pp[i].m == 0) continue;
            LL res = k;
            int j = i;
            ans += (pp[i].x * 2);
            while(j < pn) {
                if(res >= pp[j].m) {
                    res -= pp[j].m;
                    pp[j].m = 0;
                    j++;
                }
                else {
                    pp[j].m -= res;
                    res = 0;
                    i = j - 1;
                    break;
                }
            }
        }
        for(int i = 0; i < nn; ++i) {
            if(np[i].m > k) {
                LL temp = np[i].m / k;
                np[i].m = np[i].m % k;
                ans += (temp * np[i].x * -2);
                i--;
                continue;
            }
            if(np[i].m == 0) continue;
            LL res = k;
            int j = i;
            ans -= (np[i].x * 2);
            while(j < nn) {
                if(res >= np[j].m) {
                    res -= np[j].m;
                    np[j].m = 0;
                    j++;
                }
                else {
                    np[j].m -= res;
                    res = 0;
                    i = j - 1;
                    break;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
