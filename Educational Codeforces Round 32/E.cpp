#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 20;
int n;
int m;
int a[maxn];
int b[maxn];
set<int> s1;
set<int> s2;

void work(set<int> &s, int len, int *val) {
    for(int i = 0; i < (1 << len); ++i) {
        int temp = 0;
        for(int j = 0; j < len; ++j) {
            if((i >> j) & 1) {
                temp = (temp + val[j + 1]) % m;
            }
        }
        s.insert(temp);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int mid = n / 2;
    for(int i = 1; i <= mid; ++i) scanf("%d", &a[i]);
    for(int i = mid + 1; i <= n; ++i) scanf("%d", &b[i - mid]);
    work(s1, mid, a);
    work(s2, n - mid, b);
    int ans = 0;
    set<int>::iterator it;
    for(const int& x : s1) {
        if(x == m - 1) {
            ans = m - 1;
            break;
        }
        it = s2.upper_bound(m - 1 - x);
        it--;
        ans = max(*it + x, ans);
    }
    printf("%d\n", ans);
    return 0;
}
