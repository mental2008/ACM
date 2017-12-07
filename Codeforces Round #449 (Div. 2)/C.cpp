#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxn = 1e5 + 5;
char f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char f1[] = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
char A[] = "What are you doing while sending \"";
char B[] = "\"? Are you busy? Will you send \"";
char C[] = "\"?";
ULL f[maxn];
int a, b, c;

char solve(int n, LL k) {
    if(n == 0) {
        int len = strlen(f0);
        if(k <= len) return f0[(int)k - 1];
        else return '.';
    }
    else {
        if(k <= a) return A[k - 1];
        else {
            if(f[n - 1] == -1 || a + f[n - 1] >= k) {
                return solve(n - 1, k - a);
            }
            else {
                if(k <= a + f[n - 1] + b) {
                    return B[(int)(k - a - f[n - 1] - 1)];
                }
                else if(k <= a + b + f[n - 1] * 2) {
                    return solve(n - 1, k - a - f[n - 1] - b);
                }
                else if(k <= a + b + c + f[n - 1] * 2){
                    return C[(int)(k - a - b - 2 * f[n - 1] - 1)];
                }
                else return '.';
            }
        }
    }
}

int main() {
    mem(f, -1);
    f[0] = strlen(f0);
    int add = strlen(f1);
    a = strlen(A), b = strlen(B), c = strlen(C);
    for(int i = 1; i < maxn; ++i) {
        f[i] = f[i - 1] * 2 + add;
        if(f[i] > 1000000000000000000) {
            break;
        }
    }
    int q;
    string ans;
    cin >> q;
    while(q--) {
        int n;
        LL k;
        cin >> n >> k;
        ans += solve(n, k);
    }
    cout << ans << '\n';
    return 0;
}
