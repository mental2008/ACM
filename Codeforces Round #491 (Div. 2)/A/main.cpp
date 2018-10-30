#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    a = a - c;
    b = b - c;
    int d = n - a - b - c;
    if(a < 0 || b < 0 || d < 1) {
        puts("-1");
    }
    else {
        printf("%d\n", d);
    }
    return 0;
}
