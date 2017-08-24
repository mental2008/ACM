#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 2505;
char text[maxn];
char pattern[maxn];
bool dp[maxn][maxn];
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%s", text + 1);
        scanf("%s", pattern + 1);
        mem(dp, 0);
        dp[0][0] = 1;
        int len1 = strlen(text + 1);
        int len2 = strlen(pattern + 1);
        for(int i = 1; i <= len2; ++i) {
            if(i == 2 && pattern[i] == '*') dp[i][0] |= dp[i - 2][0];
            for(int j = 1; j <= len1; ++j) {
                if(pattern[i] == text[j] || pattern[i] == '.') dp[i][j] = dp[i - 1][j - 1];
                else if(pattern[i] == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i - 2][j];
                    if(text[j] == text[j - 1]) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                    if(dp[i][j]) {
                        while(j < len1 && text[j + 1] == text[j]) dp[i][++j] = 1;
                    }
                }
            }
        }
        printf("%s\n", dp[len2][len1] ? "yes" : "no");
    }
    return 0;
}
