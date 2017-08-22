#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
int nxt[maxn];
int extend[maxn];
char s1[maxn];
char s2[maxn];

void reverse(char *ch) {
    int len = strlen(ch);
    for(int i = 0; i <= (len - 1) / 2; ++i) {
        char temp = ch[i];
        ch[i] = ch[len - 1 - i];
        ch[len - 1 - i] = temp;
    }
}

void getNext(char *ch) {
    int len = strlen(ch);
    nxt[0] = len;
    int j = 0;
    while(j + 1 < len && ch[j + 1] == ch[j]) ++j;
    nxt[1] = j;
    int k = 1;
    for(int i = 2; i < len; ++i) {
        int pos = nxt[k] + k - 1;
        int L = nxt[i - k];
        if(i + L < pos + 1) nxt[i] = L;
        else {
            j = max(0, pos - i + 1);
            while(i + j < len && ch[i + j] == ch[j]) ++j;
            nxt[i] = j;
            k = i;
        }
    }
}

void extendKMP(char *s, char *t) {
    int lens = strlen(s);
    int lent = strlen(t);
    getNext(t);
    int j = 0;
    while(j < lent && j < lens && s[j] == t[j]) ++j;
    extend[0] = j;
    int k = 0;
    for(int i = 1; i < lens; ++i) {
        int pos = extend[k] + k - 1;
        int L = nxt[i - k];
        if(i + L < pos + 1) extend[i] = L;
        else {
            j = max(0, pos - i + 1);
            while(i + j < lens && j < lent && s[i + j] == t[j]) ++j;
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%s", s1);
        scanf("%s", s2);
        reverse(s1);
        reverse(s2);
        extendKMP(s1, s2);
        LL ans = 0;
        int len = strlen(s1);
        for(int i = 0; i < len; ++i) {
            ans = (ans + ((1LL * extend[i] * (extend[i] + 1) / 2) % MOD)) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//扩展KMP
