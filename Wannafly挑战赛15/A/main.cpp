#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
struct Node {
    int weight;
    int price;
    bool operator < (const Node& e) const {
        if(weight == e.weight) return price < e.price;
        return weight > e.weight;
    }
} node[maxn];
priority_queue<int, vector<int>, greater<int> > st;

bool cmp(int x, int y) {
    return x > y;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &node[i].weight, &node[i].price);
    }
    sort(node, node + m);
    while(!st.empty()) st.pop();
    int pos = 0;
    bool ok = true;
    LL ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = pos; j < m; ++j, ++pos) {
            if(node[j].weight >= a[i]) {
                st.push(node[j].price);
            }
            else {
                break;
            }
        }
        if(st.empty()) {
            ok = false;
            break;
        }
        else {
            int temp = st.top();
            st.pop();
            ans += temp;
        }
    }
    if(ok) printf("%lld\n", ans);
    else puts("-1");
    return 0;
}
