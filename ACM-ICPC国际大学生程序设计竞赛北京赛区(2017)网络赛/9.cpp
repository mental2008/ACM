#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = (1 << 19 + 5);
int k;
LL val[maxn];
struct Node {
    int neg;
    int pos;
    LL minPosNum;
    LL minNegNum;
    LL maxPosNum;
    LL maxNegNum;
} node[maxn];

void build(int root, int l, int r) {
    if(l == r) {
        if(val[l] >= 0) {
            node[root].neg = 0;
            node[root].pos = 1;
            node[root].minPosNum = node[root].maxPosNum = val[l];
            node[root].minNegNum = INF;
            node[root].maxNegNum = -INF;
        }
        else {
            node[root].neg = 1;
            node[root].pos = 0;
            node[root].minPosNum = INF;
            node[root].maxPosNum = -INF;
            node[root].minNegNum = node[root].maxNegNum = val[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build((root << 1) + 1, mid + 1, r);
    node[root].neg = node[root << 1].neg + node[(root << 1) + 1].neg;
    node[root].pos = node[root << 1].pos + node[(root << 1) + 1].pos;
    // printf("l = %d, r = %d, neg = %d\n", l, r, node[root].neg);
    node[root].minPosNum = min(node[root << 1].minPosNum, node[(root << 1) + 1].minPosNum);
    node[root].maxPosNum = max(node[root << 1].maxPosNum, node[(root << 1) + 1].maxPosNum);
    node[root].minNegNum = min(node[root << 1].minNegNum, node[(root << 1) + 1].minNegNum);
    node[root].maxNegNum = max(node[root << 1].maxNegNum, node[(root << 1) + 1].maxNegNum);
    return;
}

void update(int root, int l, int r, int index) {
    if(l > index || r < index) return;
    if(l == r) {
        if(val[l] >= 0) {
            node[root].neg = 0;
            node[root].pos = 1;
            node[root].minPosNum = node[root].maxPosNum = val[l];
            node[root].minNegNum = INF;
            node[root].maxNegNum = -INF;
        }
        else {
            node[root].neg = 1;
            node[root].pos = 0;
            node[root].minPosNum = INF;
            node[root].maxPosNum = -INF;
            node[root].minNegNum = node[root].maxNegNum = val[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(root << 1, l, mid, index);
    update((root << 1) + 1, mid + 1, r, index);
    node[root].neg = node[root << 1].neg + node[(root << 1) + 1].neg;
    node[root].pos = node[root << 1].pos + node[(root << 1) + 1].pos;
    node[root].minPosNum = min(node[root << 1].minPosNum, node[(root << 1) + 1].minPosNum);
    node[root].maxPosNum = max(node[root << 1].maxPosNum, node[(root << 1) + 1].maxPosNum);
    node[root].minNegNum = min(node[root << 1].minNegNum, node[(root << 1) + 1].minNegNum);
    node[root].maxNegNum = max(node[root << 1].maxNegNum, node[(root << 1) + 1].maxNegNum);
}

bool haveNeg(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return false;
    if(l >= ql && r <= qr) {
        if(node[root].neg > 0) return true;
        else return false;
    }
    int mid = (l + r) >> 1;
    return (haveNeg(root << 1, l, mid, ql, qr) || haveNeg((root << 1) + 1, mid + 1, r, ql, qr));
}

bool havePos(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return false;
    if(l >= ql && r <= qr) {
        if(node[root].pos > 0) return true;
        else return false;
    }
    int mid = (l + r) >> 1;
    return (havePos(root << 1, l, mid, ql, qr) || havePos((root << 1) + 1, mid + 1, r, ql, qr));
}

LL query1(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) {
        return node[root].minNegNum;
    }
    int mid = (l + r) >> 1;
    return min(query1(root << 1, l, mid, ql, qr), query1((root << 1) + 1, mid + 1, r, ql, qr));
}//最小负数

LL query2(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) {
        return node[root].maxPosNum;
    }
    int mid = (l + r) >> 1;
    return max(query2(root << 1, l, mid, ql, qr), query2((root << 1) + 1, mid + 1, r, ql, qr));
}//最大正数

LL temp1;

void query3(int root, int l, int r, int ql, int qr, int &sign) {
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        if(node[root].maxNegNum <= temp1) return;
    }
    if(l == r) {
        if(temp1 < val[l]) {
            temp1 = val[l];
            sign = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    query3(root << 1, l, mid, ql, qr, sign);
    query3((root << 1) + 1, mid + 1, r, ql, qr, sign);
}//最大负数

LL temp2;

void query4(int root, int l, int r, int ql, int qr, int &sign) {
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        if(node[root].maxNegNum >= temp2) return;
    }
    if(l == r) {
        if(temp2 > val[l]) {
            temp2 = val[l];
            sign = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    query4(root << 1, l, mid, ql, qr, sign);
    query4((root << 1) + 1, mid + 1, r, ql, qr, sign);
}//最大负数

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &k);
        for(int i = 0; i < (1 << k); ++i) {
            scanf("%lld", &val[i]);
        }
        build(1, 0, (1 << k) - 1);
        int q;
        scanf("%d", &q);
        while(q--) {
            int order;
            scanf("%d", &order);
            if(order == 1) {
                int l, r;
                scanf("%d%d", &l, &r);
                LL ans;
                bool Neg = haveNeg(1, 0, (1 << k) - 1, l, r);
                bool Pos = havePos(1, 0, (1 << k) - 1, l, r);
                // cout << Neg << " " << Pos << endl;
                if(Neg == 1 && Pos == 1) {
                    ans = query1(1, 0, (1 << k) - 1, l, r) * query2(1, 0, (1 << k) - 1, l, r);
                    // cout << query1(1, 0, (1 << k) - 1, l, r) << " " << query2(1, 0, (1 << k) - 1, l, r) << endl;
                }//有负有正
                else if(Neg == 1 && Pos == 0) {
                    temp1 = -INF;
                    int sign;
                    query3(1, 0, (1 << k) - 1, l, r, sign);
                    ans = val[sign] * val[sign];
                }//只有负
                else {
                    temp2 = INF;
                    int sign;
                    query4(1, 0, (1 << k) - 1, l, r, sign);
                    ans = val[sign] * val[sign];
                }//只有正
                printf("%lld\n", ans);
            }
            else {
                int x;
                LL y;
                scanf("%d%lld", &x, &y);
                val[x] = y;
                update(1, 0, (1 << k) - 1, x);
            }
        }
    }
    return 0;
}
