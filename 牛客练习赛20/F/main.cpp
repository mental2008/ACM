#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL val[10];
LL n;

bool judge() {
    for(int i = 1; i < 10; ++i) {
        if(val[i] <= n) return true;
    }
    return false;
}

int main()
{
    scanf("%lld", &n);
    for(int i = 1; i < 10; ++i) {
        scanf("%lld", &val[i]);
    }
    if(judge()) {
        LL len = 0, index = 10;
        for(int i = 9; i >= 1; --i) {
            LL temp = n / val[i];
            if(len < temp) {
                index = i;
                len = temp;
            }
        }
        for(int i = 0; i < len; ++i) {
            printf("%d", index);
        }
        puts("");
    }
    else puts("-1");
    return 0;
}
