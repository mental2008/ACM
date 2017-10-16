#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) {
            puts("Not a moose");
            continue;
        }
        if(n > m) swap(n, m);
        if(n == m) {
            printf("Even %d\n", n + m);
        }
        else {
            printf("Odd %d\n", 2 * m);
        }
    }
    return 0;
}
