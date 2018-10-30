#include <bits/stdc++.h>
using namespace std;
int m, n;
int p[35];

int main()
{
    cin >> m >> n;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < n; ++i) {
        cout << "1\n";
        fflush(stdout);
        int res;
        cin >> res;
        if(res == 0) {
            return 0;
        }
        if(res == 1) {
            p[i] = 1;
        }
        else {
            p[i] = 0;
        }
    }
    int l = 1, r = m;
    int cnt = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        cout << mid << "\n";
        fflush(stdout);
        int res;
        cin >> res;
        if(res == 0) {
            return 0;
        }
        if(p[cnt] == 1) {
            if(res == 1) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        else {
            if(res == 1) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cnt = (cnt + 1) % n;
    }

    return 0;
}
