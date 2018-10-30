#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
struct Node {
    int type;
    int fa;
    int val;
    int lson, rson;
    int lval, rval;
} node[maxn];
int cnt1, cnt2, cnt3;
int vec[maxn];
int need[maxn];
int ans[maxn];
int deg[maxn];
int res;

void dfs(int u, int last, int son) {
    if(last == -1) {
        dfs(node[u].fa, !node[u].val, u);
        return;
    }
    if(u == -1) {
        ans[cnt3++] = last;
        return;
    }
    if(node[u].type == 0) {
        int temp = 1;
        if(node[u].lson == son) {
            temp = (temp & last) & node[u].rval;
        }
        else if(node[u].rson == son) {
            temp = (temp & last) & node[u].lval;
        }
        if(temp == node[u].val) ans[cnt3++] = res;
        else dfs(node[u].fa, temp, u);
        return;
    }
    else if(node[u].type == 1) {
        int temp = 0;
        if(node[u].lson == son) {
            temp = (temp | last) | node[u].rval;
        }
        else if(node[u].rson == son) {
            temp = (temp | last) | node[u].lval;
        }
        if(temp == node[u].val) ans[cnt3++] = res;
        else dfs(node[u].fa, temp, u);
        return;
    }
    else if(node[u].type == 2) {
        int temp = 0;
        if(node[u].lson == son) {
            temp = (temp ^ last) ^ node[u].rval;
        }
        else if(node[u].rson == son) {
            temp = (temp ^ last) ^ node[u].lval;
        }
        if(temp == node[u].val) ans[cnt3++] = res;
        else dfs(node[u].fa, temp, u);
        return;
    }
    else if(node[u].type == 3) {
        dfs(node[u].fa, !last, u);
        return;
    }
}

void addSon(int fa, int son) {
    if(node[fa].lson == 0) {
        node[fa].lson = son;
        node[fa].lval = node[son].val;
    }
    else {
        node[fa].rson = son;
        node[fa].rval = node[son].val;
    }
}

int main()
{
    scanf("%d", &n);
    cnt1 = cnt2 = cnt3 = 0;
    for(int i = 1; i <= n; ++i) {
        node[i].lson = node[i].rson = 0;
        char s[5];
        scanf("%s", s);
        if(s[0] == 'A') {
            int x, y;
            scanf("%d%d", &x, &y);
            node[i].type = 0;
            node[x].fa = i;
            node[y].fa = i;
            node[i].val = 1;
            deg[i] = 2;
        }
        else if(s[0] == 'O') {
            int x, y;
            scanf("%d%d", &x, &y);
            node[i].type = 1;
            node[x].fa = i;
            node[y].fa = i;
            node[i].val = 0;
            deg[i] = 2;
        }
        else if(s[0] == 'X') {
            int x, y;
            scanf("%d%d", &x, &y);
            node[i].type = 2;
            node[x].fa = i;
            node[y].fa = i;
            node[i].val = 0;
            deg[i] = 2;
        }
        else if(s[0] == 'N') {
            int x;
            scanf("%d", &x);
            node[i].type = 3;
            node[x].fa = i;
            deg[i] = 1;
        }
        else {
            int x;
            scanf("%d", &x);
            node[i].type = 4;
            node[i].val = x;
            vec[cnt1++] = i;
            need[cnt2++] = i;
        }
    }
    node[1].fa = -1;
    for(int i = 0; i < cnt1; ++i) {
        int x = node[vec[i]].fa;
        if(x == -1) break;
        if(node[x].type == 0) node[x].val = node[x].val & node[vec[i]].val;
        else if(node[x].type == 1) node[x].val = node[x].val | node[vec[i]].val;
        else if(node[x].type == 2) node[x].val = node[x].val ^ node[vec[i]].val;
        else if(node[x].type == 3) node[x].val = (!node[vec[i]].val);
        addSon(x, vec[i]);
        deg[x]--;
        if(deg[x] == 0) vec[cnt1++] = x;
    }
    res = node[1].val;
    for(int i = 0; i < cnt2; ++i) {
        dfs(need[i], -1, -1);
    }
    for(int i = 0; i < cnt3; ++i) {
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
