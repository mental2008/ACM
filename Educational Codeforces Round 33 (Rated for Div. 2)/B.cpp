#include <bits/stdc++.h>
using namespace std;
int main() {
    int val[15];
    for(int i = 1; i <= 10; ++i) {
        val[i] = ((1 << i) - 1) * (1 << (i - 1));
    }
    int n;
    scanf("%d", &n);
    int ans;
    for(int i = 10; i >= 1; --i) {
        if(n % val[i] == 0) {
            ans = val[i];
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
