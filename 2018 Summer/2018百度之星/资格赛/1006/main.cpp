#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;

#define rep(i, a, b) for(int i = a; i <= b; ++i)

struct Node {
    int weight;
    int type;
    bool vis;
    int u, v;
    bool operator < (const Node& e) const {
        return weight < e.weight;
    }
} node[maxn];
int n, m;
int fa[maxn];

int _find(int x) {
    return (fa[x] == x ? x : fa[x] = _find(fa[x]));
}

bool connect(int x, int y) {
    int a = _find(x);
    int b = _find(y);
    if(a == b) return false;
    else {
        fa[a] = b;
        return true;
    }
}

int work1(int limit) {
    rep(i, 1, m) node[i].vis = 0;
    rep(i, 1, n) fa[i] = i;
    int res = 0;
    int cnt = 0;
    rep(i, 1, m) {
        if(node[i].type == 0 || node[i].type == 1) {
            if(connect(node[i].u, node[i].v)) {
                res += node[i].weight;
                node[i].vis = 1;
                cnt++;
            }
        }
    }
    if(cnt > limit) return -1;
    rep(i, 2, n) {
        int x = _find(i);
        int y = _find(i - 1);
        if(x != y) return -1;
    }
    rep(i, 1, m) {
        if(cnt == limit) return res;
        if(node[i].vis == 0) {
            node[i].vis = 1;
            res += node[i].weight;
            cnt++;
        }
    }
    return res;
}

int work2(int limit) {
    rep(i, 1, m) node[i].vis = 0;
    rep(i, 1, n) fa[i] = i;
    int res = 0;
    int cnt = 0;
    rep(i, 1, m) {
        if(node[i].type == 2 || node[i].type == 1) {
            if(connect(node[i].u, node[i].v)) {
                res += node[i].weight;
                node[i].vis = 1;
                cnt++;
            }
        }
    }
    if(cnt > limit) return -1;
    rep(i, 2, n) {
        int x = _find(i);
        int y = _find(i - 1);
        if(x != y) return -1;
    }
    rep(i, 1, m) {
        if(cnt == limit) return res;
        if(node[i].vis == 0) {
            node[i].vis = 1;
            res += node[i].weight;
            cnt++;
        }
    }
    return res;
}

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    rep(T, 1, caseCnt) {
        scanf("%d%d", &n, &m);
        rep(i, 1, m) {
            scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].weight);
            char s[4];
            scanf("%s", s);
            if(s[0] == 'R') node[i].type = 0;
            else if(s[0] == 'G') node[i].type = 1;
            else node[i].type = 2;
        }
        sort(node + 1, node + 1 + m);
        printf("Case #%d:\n", T);
        rep(i, 1, m) {
            int ans1 = work1(i);
            int ans2 = work2(i);
            if(ans1 == -1) {
                printf("%d\n", ans2);
            }
            else if(ans2 == -1){
                printf("%d\n", ans1);
            }
            else {
                printf("%d\n", min(ans1, ans2));
            }
        }
    }
    return 0;
}
