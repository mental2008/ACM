#include <bits/stdc++.h>
using namespace std;
int main() {
    int v1, v2, v3, vm;
    scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
    for(int i = 0; i <= 250; ++i) {
        for(int j = 0; j < i; ++j) {
            for(int k = 0; k < j; ++k) {
                if(i >= v1 && i <= 2 * v1 && j <= 2 * v2 && j >= v2 && k >= v3 && k <= 2 * v3 && k >= vm && j > 2 * vm && k <= 2 * vm) {
                    printf("%d\n%d\n%d\n", i, j, k);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}
