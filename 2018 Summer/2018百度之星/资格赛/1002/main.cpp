#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
char s[maxn];
int n, q;
struct Segment {
    int cnt[26];
} seg[maxn * 4];

void build(int root, int l, int r) {
    memset(seg[root].cnt, 0, sizeof(seg[root].cnt));
    if(l == r) {
        int index = s[l] - 'A';
        seg[root].cnt[index]++;
        return;
    }
    int mid = (l + r) >> 1;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    for(int i = 0; i < 26; ++i) {
        seg[root].cnt[i] = seg[root * 2].cnt[i] + seg[root * 2 + 1].cnt[i];
    }
}

pii query(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return make_pair(26, 0);
    if(l >= ql && r <= qr) {
        for(int i = 0; i < 26; ++i) {
            if(seg[root].cnt[i] != 0) {
                return make_pair(i, seg[root].cnt[i]);
            }
        }
    }
    int mid = (l + r) >> 1;
    pii lson = query(root * 2, l, mid, ql, qr);
    pii rson = query(root * 2 + 1, mid + 1, r, ql, qr);
    if(lson.first == rson.first) return make_pair(lson.first, lson.second + rson.second);
    else if(lson.first < rson.first) return lson;
    else return rson;
}

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    rep(T, 1, caseCnt) {
        scanf("%d%d", &n, &q);
        scanf("%s", s + 1);
        printf("Case #%d:\n", T);
        build(1, 1, n);
        while(q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            pii ans = query(1, 1, n, l, r);
            printf("%d\n", ans.second);
        }
    }
    return 0;
}
