#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 2505;
const LL INF = 0x3f3f3f3f3f3f3f3f;
map<LL, int> mp;
int n;
int vis[maxn][3 * maxn];
LL a[maxn][3 * maxn];
int match[maxn];
LL num[maxn];
LL result[3 * maxn];
bool vis_num[maxn];
bool vis_result[3 * maxn];
int nummap[maxn];
int cnt;
LL p[maxn], q[maxn];
LL d;

bool dfs(int i) {
    vis_num[i] = 1;
    for(int j = 1; j <= cnt; ++j) {
        if(!vis[i][j]) continue;
        if(vis_result[j]) continue;
        LL gap = num[i] + result[j] - a[i][j];
        if(gap == 0) {
			vis_result[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
                nummap[i] = j;
				return true;
			}
		}
		else d = min(d, gap);
    }
    return false;
}

void KM() {
    mem(nummap, -1);
    mem(match, -1);
    mem(result, 0);
    for(int i = 0; i < n; ++i) {
        num[i] = -INF;
        for(int j = 1; j <= cnt; ++j) {
            if(vis[i][j]) {
                num[i] = max(num[i], a[i][j]);
            }
        }
        if(num[i] == -INF) {
            puts("impossible");
            return;
		}
    }
    for(int i = 0; i < n; ++i) {
		while(1) {
            mem(vis_num, 0);
            mem(vis_result, 0);
			d = INF;
			if(dfs(i)) break;
			if(d == INF) {
				puts("impossible");
				return;
			}
			for(int j = 0; j < n; j++) if(vis_num[j]) num[j] -= d;
			for(int j = 1; j <= cnt; j++) if(vis_result[j]) result[j] += d;
		}
	}
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(num[i] == -1 || num[j] == -1 || nummap[i] == nummap[j]) {
                puts("impossible");
				return;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(vis[i][nummap[i]] == 1) {
            printf("%lld + %lld = %lld\n", p[i], q[i], p[i] + q[i]);
        }
        else if(vis[i][nummap[i]] == 2) {
            printf("%lld - %lld = %lld\n", p[i], q[i], p[i] - q[i]);
        }
        else {
            printf("%lld * %lld = %lld\n", p[i], q[i], p[i] * q[i]);
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        mp.clear();
        mem(vis, 0);
        cnt = 0;
        for(int i = 0; i < n; ++i) {
            LL u, v;
            scanf("%lld%lld", &u, &v);
            p[i] = u, q[i] = v;
            LL x = u + v, y = u - v, z = u * v;
            if(mp[x]) {
                vis[i][mp[x]] = 1;
                a[i][mp[x]] = 1;
            }
            else {
                mp[x] = ++cnt;
                vis[i][mp[x]] = 1;
                a[i][mp[x]] = 1;
            }
            if(mp[y]) {
                vis[i][mp[y]] = 2;
                a[i][mp[y]] = 1;
            }
            else {
                mp[y] = ++cnt;
                vis[i][mp[y]] = 2;
                a[i][mp[y]] = 1;
            }
            if(mp[z]) {
                vis[i][mp[z]] = 3;
                a[i][mp[z]] = 1;
            }
            else {
                mp[z] = ++cnt;
                vis[i][mp[z]] = 3;
                a[i][mp[z]] = 1;
            }
        }
        KM();
    }
    return 0;
}
