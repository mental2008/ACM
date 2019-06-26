#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e7 + 5;
int a[maxn];
int n, m, k, p, q, r, MOD;
int maxrating[maxn];
int cnt[maxn];
int deq[maxn];

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &MOD);
        for(int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = k + 1; i <= n; ++i) {
            a[i] = (1LL * p * a[i - 1] + 1LL * q * i + 1LL * r) % MOD;
        }
        int head, tail;
        head = tail = 1;
        deq[1] = n;
        for(int i = n - 1; i >= n - m + 1; --i) {
            if(a[deq[tail]] > a[i]) deq[++tail] = i;
            else {
                while(head <= tail && a[deq[tail]] <= a[i]) tail--;
                tail = tail + 1;
                deq[tail] = i;
            }
        }
        maxrating[n - m + 1] = a[deq[head]];
        cnt[n - m + 1] = tail - head + 1;
        for(int i = n - m; i >= 1; --i) {
            while(deq[head] >= i + m) head++;
            if(a[deq[tail]] > a[i]) deq[++tail] = i;
            else {
                while(head <= tail && a[deq[tail]] <= a[i]) tail--;
                tail = tail + 1;
                deq[tail] = i;
            }
            maxrating[i] = a[deq[head]];
            cnt[i] = tail - head + 1;
        }
        LL A, B;
        A = B = 0;
        for(int i = 1; i <= n - m + 1; ++i) {
            A = A + (maxrating[i] ^ i);
            B = B + (cnt[i] ^ i);
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}
