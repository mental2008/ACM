#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e5 + 5;
int a[6];
int n;

int main()
{
    scanf("%d", &n);
    mem(a, 0);
    for(int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        a[val]++;
    }
    int ans = 0;
    ans += a[5];
    int temp = min(a[1], a[4]);
    ans += temp;
    a[1] -= temp;
    a[4] -= temp;
    ans += a[4];
    temp = min(a[2], a[3]);
    ans += temp;
    a[2] -= temp;
    a[3] -= temp;
    if(a[2]) {
        temp = a[2] / 2;
        a[2] -= (2 * temp);
        a[1] -= temp;
        ans += temp;
        if(a[2]) {
            ans++;
            a[1] -= 3;
        }
        if(a[1] > 0) {
            ans += (a[1] / 5 + 1);
            if(a[1] % 5 == 0) ans--;
        }
        printf("%d\n", ans);
    }
    else {
        ans += a[3];
        a[1] -= (2 * a[3]);
        if(a[1] > 0) {
            ans += (a[1] / 5 + 1);
            if(a[1] % 5 == 0) ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
