#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
int a[maxn][maxn];

int main()
{
    freopen("out.txt", "w", stdout);
    puts("2000");
    int p = 47;
    for(int i = 0; i < p; ++i) {
        for(int j = 0; j < p; ++j) {
            for(int k = 0; k < p; ++k) {
                a[i * p + j][k * p + (j * k + i) % p] = 1;
            }
        }
    }
    for(int i = 0; i < 2000; ++i) {
        for(int j = 0; j < 2000; ++j) {
            printf("%d", a[i][j]);
        }
        puts("");
    }
    return 0;
}
