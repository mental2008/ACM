#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    int last = n % 10;
    if(last > 5) n = n - last + 10;
    else n = n - last;
    printf("%d\n", n);
    return 0;
}
