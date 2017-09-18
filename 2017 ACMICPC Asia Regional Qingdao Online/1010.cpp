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
int n;
bool vis[maxn];
int val[maxn];
int pre[maxn];
int nxt[maxn];
set<int> st;
vector<int> vec;

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        st.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
            vis[i] = 0;
            pre[i] = i - 1;
            nxt[i] = i + 1;
            st.insert(i);
        }
        vis[0] = vis[n + 1] = 0;
        val[0] = 0;
        nxt[0] = 1;
        val[n + 1] = maxn;
        pre[n + 1] = n;
        while(st.size()) {
            vec.clear();
            for(auto &x : st) {
                if(x == 0 || x == n + 1) continue;
                int nxtx = nxt[x];
                int prex = pre[x];
                if(val[x] < val[prex]) {
                    vec.push_back(prex);
                    vec.push_back(x);
                }
                if(val[x] > val[nxtx]) {
                    vec.push_back(x);
                    vec.push_back(nxtx);
                }
            }
            st.clear();
            for(auto &x : vec) {
                if(!vis[x]) {
                    int nxtx = nxt[x];
                    int prex = pre[x];
                    pre[nxtx] = prex;
                    nxt[prex] = nxtx;
                    st.insert(prex);
                    vis[x] = 1;
                }
            }
        }
        int count = 0;
        for(int i = nxt[0]; i != n + 1; i = nxt[i]) count++;
        printf("%d\n", count);
        for(int i = nxt[0]; i != n + 1; i = nxt[i]) printf("%d ", val[i]);
        puts("");
    }
    return 0;
}
