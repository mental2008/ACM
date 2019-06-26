#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[5005];
int b[5005];
int p[5005];
bool sign[5005];
bool vis[maxn];
vector<int> prime;
int ans[5005];

int main()
{
    mem(vis, 0);
    prime.clear();
    for(int i = 2; i < maxn; ++i) {
        if(vis[i] == 0) {
            prime.push_back(i);
            for(int j = i * 2; j < maxn; j += i) {
                vis[j] = 1;
            }
        }
    }
    int len = (int)prime.size();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int res = 1;
        if(a[i] < 0) {
            res *= -1;
            a[i] = -a[i];
        }
        for(int j = 0; j < len; ++j) {
            if(a[i] < prime[j]) break;
            if(a[i] % prime[j] == 0) {
                int cnt = 0;
                while(a[i] % prime[j] == 0) {
                    cnt++;
                    a[i] /= prime[j];
                }
                if(cnt % 2 == 1) {
                    res *= prime[j];
                }
            }
        }
        if(a[i] != 1) {
            res *= a[i];
        }
        b[i] = a[i] = res;
    }
    sort(b, b + n);
    for(int i = 0; i < n; ++i) {
        int pos = lower_bound(b, b + n, a[i]) - b;
        p[i] = pos;
        // cout << "i = " << i << " val = " << p[i] << '\n';
    }
    mem(ans, 0);
    for(int i = 0; i < n; ++i) {
        mem(sign, 0);
        int res = 0;
        bool nonzero = false;
        for(int j = i; j < n; ++j) {
            if(a[j] == 0) {
                if(nonzero == false) ans[1]++;
                else ans[res]++;
                continue;
            }
            nonzero = true;
            if(sign[p[j]] == 0) {
                res++;
                sign[p[j]] = 1;
            }
            ans[res]++;
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
