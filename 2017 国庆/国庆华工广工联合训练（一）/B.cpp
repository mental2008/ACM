#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
char ch[maxn];
int main() {
    int n;
    while(~scanf("%d", &n)) {
        LL sum = 1LL * n * (n + 1) / 2;
        if(sum % 2) {
            puts("-1");
            continue;
        }
        sum /= 2;
        int sum1 = 0, sum2 = 0;
        for(int i = 1; i <= n; ++i) {
            int res = i % 4;
            if(res == 1) ch[i] = '-';
            else if(res == 2) ch[i] = '+';
            else if(res == 3) ch[i] = '+';
            else ch[i] = '-';
            if(res == 1 || res == 0) sum1 += i;
            else sum2 += i;
        }
        for(int i = 1; i < n; ++i) {
            if(sum1 == sum2) break;
            if(ch[i] == ch[i + 1]) continue;
            if(ch[i] == '-' && ch[i + 1] == '+') {
                if(sum1 < sum2) {
                    ch[i] = '+';
                    ch[i + 1] = '-';
                    sum2--;
                    sum1++;
                }
            }
            else {
                if(sum1 > sum2) {
                    ch[i] = '-';
                    ch[i + 1] = '+';
                    sum2++;
                    sum1--;
                }
            }
        }
        if(sum1 == sum2) {
            for(int i = 1; i <= n; ++i) {
                printf("%c", ch[i]);
            }
            puts("");
        }
        else puts("-1");
    }
    return 0;
}
