#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int n, q;
LL a[maxn];
LL MIN[maxn];
int MAGIC = 500;

void init() {
    fill(MIN, MIN + maxn, 0x3f3f3f3f3f3f3f3f);
    for (int i = 0; i < n; ++i) {
        if (i % MAGIC == 0 || a[i] < MIN[i / MAGIC]) {
            MIN[i / MAGIC] = a[i];
        }
    }
}

int query(int l, int r, LL v) {
    for (int j = l; j <= r; ) {
        if (j % MAGIC == 0 && j + MAGIC - 1 <= r) {
            if(MIN[j / MAGIC] <= v) {
                for(int i = j; i < j + MAGIC; ++i) {
                    if(a[i] <= v) return i;
                }
            }
            j += MAGIC;
        }
        else {
            if(a[j] <= v) {
                return j;
            }
            j++;
        }
    }
    return -1;
}

int main() {
    while(~scanf("%d%d", &n, &q)) {
        for(int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        init();
        while(q--) {
            LL v;
            int l, r;
            scanf("%lld%d%d", &v, &l, &r);
            l--, r--;
            while(l <= r) {
                int index = query(l, r, v);
                if(index == -1) break;
                l = index + 1;
                v %= a[index];
            }
            printf("%lld\n", v);
        }
    }
    return 0;
}
