#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 100005;
char s[maxn];
char t[12];
int nxt[12];
int n;
int value[maxn];
struct Node {
    int l, r;
    int val;
} node[3 * maxn];

void getNext(char *ch) {
	int len = strlen(ch);
    nxt[0] = 0, nxt[1] = 0;
	for(int i = 1; i < len; i++) {
		int j = nxt[i];
		while(j && ch[i] != ch[j]) j = nxt[j];
		nxt[i + 1] = ch[i] == ch[j] ? j + 1 : 0;
	}
}

void build(int root, int l, int r) {
    if(l == r) {
        node[root].val = value[l];
        return;
    }
    node[root].val = 0;
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    node[root].val = node[root * 2].val + node[root * 2 + 1].val;
}

void update(int root, int l, int r, int index, int change) {
    if(r < index || l > index) return;
    if(l == index && r == index) {
        value[index] = change;
        node[root].val = change;
        return;
    }
    int mid = (l + r) / 2;
    update(root * 2, l, mid, index, change);
    update(root * 2 + 1, mid + 1, r, index, change);
    node[root].val = node[root * 2].val + node[root * 2 + 1].val;
}

int query(int root, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(ql <= l && qr >= r) {
        return node[root].val;
    }
    int mid = (l + r) / 2;
    return query(root * 2, l, mid, ql, qr) + query(root * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        cin >> n;
        cin >> s >> t;
        int lens = strlen(s), lent = strlen(t);
        getNext(t);
        mem(value, 0);
        for(int i = 0; i < lens; ++i) {
            bool ok = true;
            for(int j = 0; j < lent; ++j) {
                if(s[i + j] != t[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) value[i + 1] = 1;
        }
        build(1, 1, lens);
        for(int i = 0; i < n; ++i) {
            char operate;
            cin >> operate;
            if(operate == 'Q') {
                int l, r;
                cin >> l >> r;
                if(r - l + 1 < lent) {
                    cout << 0 << endl;
                    continue;
                }
                int ans = query(1, 1, lens, l, r - lent + 1);
                cout << ans << endl;
            }
            else {
                int index;
                char ch;
                cin >> index >> ch;
                s[index - 1] = ch;
                int k = 0;
                for(int j = max(0, index - lent); j <= min(lens - 1, index - 2 + lent); ++j) {
                    while(k && s[j] != t[k]) k = nxt[k];
		            if(s[j] == t[k]) k++;
                    if(k == lent) {
                        k = nxt[k];
                        if(value[j + 2 - lent] == 0) {
                            update(1, 1, lens, j + 2 - lent, 1);
                        }
                    }
                    else {
                        if(j + 1 - lent >= max(0, index - lent) && value[j + 2 - lent] == 1) {
                            update(1, 1, lens, j + 2 - lent, 0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
