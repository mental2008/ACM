#include <bits/stdc++.h>
using namespace std;
int n, k;
set<int> st;

int gcd(int x, int y) {
    return (y == 0 ? x : gcd(y, x % y));
}

int main()
{
    scanf("%d%d", &n, &k);
    int g = 0;
    for(int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        g = gcd(val, g);
    }
    st.clear();
    int res = 0;
    for(int i = 0; i < k; ++i) {
        st.insert(res);
        res = (res + g) % k;
    }
    int len = (int)st.size();
    printf("%d\n", len);
    for(auto &x : st) {
        len--;
        printf("%d", x);
        if(len == 0) printf("\n");
        else printf(" ");
    }
    return 0;
}
