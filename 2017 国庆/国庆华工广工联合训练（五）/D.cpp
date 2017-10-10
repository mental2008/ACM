#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s1[25];
char s2[25];
LL fact[25];
int main() {
    fact[0] = 1;
    for(int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%s", s1);
        int len = strlen(s1);
        memcpy(s2, s1, len + 1);
        LL ans = 0;
        for(int i = 0; i < len; ++i) {
            sort(s1 + i, s1 + len);
            int index;
            if(s1[i] == s2[i]) continue;
            for(int j = i; j < len; ++j) {
                if(s1[j] == s2[i]) {
                    index = j;
                    break;
                }
            }
            LL temp = fact[len - i - 1] * (index - i);
            // printf("temp = %d\n", temp);
            for(int j = i; j < len; ++j) {
                int res = 0;
                int k = j;
                while(s1[j] == s1[k] && k < len) {
                    res++;
                    k++;
                }
                j = k - 1;
                temp /= fact[res];
            }
            // printf("index = %d, i = %d, temp = %lld\n", index, i, temp);
            ans += temp;
            swap(s1[index], s1[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
