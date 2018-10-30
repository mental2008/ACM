#include <bits/stdc++.h>
using namespace std;
int a[105];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    if(2 * sum >= 9 * n) {
        puts("0");
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        sum -= a[i];
        sum += 5;
        if(2 * sum >= 9 * n) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}
