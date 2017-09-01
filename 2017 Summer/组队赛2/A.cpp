#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);

void extend_Euclid(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    __int128_t tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

__int128_t CRT(__int128_t a[], __int128_t m[], int n)
{
    __int128_t M = 1;
    __int128_t ans = 0;
    for(int i = 1; i <= n; i++)
        M *= m[i];
    for(int i = 1; i <= n; i++)
    {
        __int128_t x, y;
        __int128_t Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}

__int128_t a[1005], b[1005];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        __int128_t ans = CRT(b, a, n);
        cout << ans << endl;
    }
    return 0;
}
