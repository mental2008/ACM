#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a = 0, b = 0;
    bool ok = true;
    for(int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        if(val == 25) a++;
        else if(val == 50) {
            if(a == 0) ok = false;
            else {
                b++;
                a--;
            }
        }
        else {
            if(a >= 1 && b >= 1) {
                a--;
                b--;
            }
            else if(b >= 3) {
                b -= 3;
            }
            else ok = false;
        }
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
