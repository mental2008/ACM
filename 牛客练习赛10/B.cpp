#include <bits/stdc++.h>
using namespace std;
stack<int> s;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        while(!s.empty()) s.pop();
        int m = n;
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d", &val);
            s.push(val);
            if(s.top() == m) {
                printf("%d", m);
                s.pop();
                if(m != 1) printf(" ");
                m--;
            }
        }
        while(!s.empty()) {
            int x = s.top();
            s.pop();
            printf("%d", x);
            if(m != 1) printf(" ");
            m--;
        }
        puts("");
    }
    return 0;
}
