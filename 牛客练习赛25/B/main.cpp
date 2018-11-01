#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn];
int f[maxn];
int n, m;
struct Node {
    ll l, r;
    Node(){}
    Node(ll _l, ll _r) {
        l = _l, r = _r;
    }
    bool operator < (const Node& e) const {
        if(r - l == e.r - e.l) return l > e.l;
        return (r - l) > (e.r - e.l);
    }
};
priority_queue<Node> Q;
struct Point {
    ll l, r;
    Point(){}
    Point(ll _l, ll _r) {
        l = _l, r = _r;
    }
    bool operator < (const Point& e) const {
        if(l == e.l) return r < e.r;
        return l < e.r;
    }
};
set<Point> st;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    f[n] = n;
    int index = n, temp = a[n];
    for(int i = n - 1; i >= 1; --i) {
        if(temp <= a[i]) {
            temp = a[i];
            index = i;
        }
        f[i] = index;
    }
    st.clear();
    while(!Q.empty()) Q.pop();
    for(int i = 1; i <= n; i = f[i] + 1) {
        Point point(i, f[i]);
        st.insert(point);
        Node node(i, f[i]);
        Q.push(node);
    }
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x] = y;
        Point point(x, n + 1);
        auto pos = lower_bound(st.begin(), st.end(), point);
        printf("%d\n", (*pos).r);
    }
    return 0;
}
