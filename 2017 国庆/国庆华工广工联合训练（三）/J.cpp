#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(~scanf("%d", &n)) {
        printf("%d\n", n ^ (n << 1));
    }
    return 0;
}
