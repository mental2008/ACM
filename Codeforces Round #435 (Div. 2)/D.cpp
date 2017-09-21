#include <bits/stdc++.h>
using namespace std;

int query(string s) {
    printf("? ");
    int len = (int)s.length();
    for(int i = 0; i < len; ++i) printf("%c", s[i]);
    printf("\n");
    fflush(stdout);
    int response;
    scanf("%d", &response);
    return response;
}

int main() {
    int n;
    scanf("%d", &n);
    string s1 = "";
    for(int i = 0; i < n; ++i) s1 += '1';
    int p1 = query(s1);
    string s2 = "0";
    for(int i = 1; i < n; ++i) s2 += '1';
    int p2 = query(s2);
    int ans1, ans0 = ans1 = 0;
    if(p1 > p2) ans1 = 1;
    else ans0 = 1;
    int l = 2, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(ans1) {
            string s = "";
            for(int i = 1; i < l; ++i) s += '1';
            for(int i = l; i <= mid; ++i) s += '0';
            for(int i = mid + 1; i <= n; ++i) s += '1';
            int p = query(s);
            int x = (mid - l + 1 + p - p1);
            if(x <= 0) l = mid + 1;
            else r = mid;
        }
        else {
            string s = "";
            for(int i = 1; i < l; ++i) s += '1';
            for(int i = l; i <= mid; ++i) s += '0';
            for(int i = mid + 1; i <= n; ++i) s += '1';
            int p = query(s);
            int x = (mid - l + 1 + p1 - p);
            if(x <= 0) l = mid + 1;
            else r = mid;
        }
    }
    if(ans1) ans0 = l;
    else ans1 = l;
    printf("! %d %d\n", ans1, ans0);
    fflush(stdout);
    return 0;
}
