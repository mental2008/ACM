#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    pair<int, int> a[25];
    int order[25];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i) order[a[i].second] = i;
    for(int i = 0; i < n; ++i) {
        printf("%d ", a[(order[i] + 1) % n]);
    }
    puts("");
    return 0;
}
