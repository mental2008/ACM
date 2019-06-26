#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int b[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    double res = m;
    if(a[1] == 1 || b[1] == 1) {
        puts("-1");
        return 0;
    }
    res = res * b[1] / (b[1] - 1);
    for(int i = n; i >= 2; --i) {
        if(a[i] == 1 || b[i] == 1) {
            puts("-1");
            return 0;
        }
        res = res * a[i] / (a[i] - 1);
        res = res * b[i] / (b[i] - 1);
    }
    res = res * a[1] / (a[1] - 1);
    printf("%.10lf\n", res - m);
    return 0;
}
