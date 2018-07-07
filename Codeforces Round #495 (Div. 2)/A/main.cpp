#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;
int n;
LL d;
LL a[maxn];
map<LL, int> mp;

int main()
{
    scanf("%d%lld", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    if(n == 1) {
        puts("2");
        return 0;
    }
    mp.clear();
    int sum = 2;
    for(int i = 1; i < n - 1; ++i) {
        if(d <= abs(a[i] - d - a[i - 1]) && mp[a[i] - d] == 0) {
            sum++;
            mp[a[i] - d] = 1;
        }
        if(d <= abs(a[i] + d - a[i + 1]) && mp[a[i] + d] == 0) {
            sum++;
            mp[a[i] + d] = 1;
        }
    }
    if(d <= abs(a[0] + d - a[1]) && mp[a[0] + d] == 0) {
        sum++;
        mp[a[0] + d] = 1;
    }
    if(d <= abs(a[n - 1] - d - a[n - 2]) && mp[a[n - 1] - d] == 0) {
        sum++;
        mp[a[n - 1] - d] = 1;
    }
    printf("%d\n", sum);
    return 0;
}
