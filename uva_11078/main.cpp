#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100000
using namespace std;
int a[maxn + 10];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int Max = a[1];
        int ans = a[1] - a[2];
        for(int i = 2; i <= n; i++) {
            ans = max(ans, Max - a[i]);
            Max = max(a[i], Max);
        }
        printf("%d\n", ans);
    }
    return 0;
}