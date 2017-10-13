#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 100005;
int n, k;
int a[maxn];
int sum;

void create(int root, int l, int r) {
    if(sum == k) {
        for(int i = l; i < r; ++i) {
            a[i] = n - i;
        }
        sort(a + l, a + r);
        return;
    }
    if(l == r - 1) {
        a[l] = n - l;
        return;
    }
    sum += 2;
    int mid = (l + r) / 2;
    create(root * 2, l, mid);
    create(root * 2 + 1, mid, r);
}

int main() {
    scanf("%d%d", &n, &k);
    sum = 1;
    create(1, 0, n);
    if(sum != k) puts("-1");
    else for(int i = 0; i < n; ++i) printf("%d%c", a[i], (i == n - 1 ? '\n' : ' '));
    return 0;
}
