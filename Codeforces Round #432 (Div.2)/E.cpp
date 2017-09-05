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
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e9 + 5;
int n;
bool prime[100005];
vector<int> vec;
vector<int> ans;
bool vis[10000][100];
map<int, int> mp;

void init() {
    mem(prime, 0);
    vec.clear();
    for(int i = 2; i < 100005; ++i) {
        if(!prime[i]) {
            vec.push_back(i);
            for(int j = i * 2; j < 100005; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
    init();
    while(~scanf("%d", &n)) {
        mem(vis, 0);
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d", &val);
            for(int j = 0; j < (int)vec.size(); ++j) {
                if(vec[j] > val) break;
                if(val % vec[j] == 0) {
                    int cnt = 0;
                    while(val % vec[j] == 0) {
                        cnt++;
                        val /= vec[j];
                    }
                    if(!vis[j][cnt]) {
                        ans.push_back(1);
                        vis[j][cnt] = 1;
                    }
                }
            }
            if(val != 1) {
                if(!mp[val]) {
                    ans.push_back(1);
                    mp[val]++;
                }
            }
        }
        int len = (int)ans.size();
        if(len == 0) puts("Arpa");
        else {
            int res = ans[0];
            for(int i = 1; i < len; ++i) {
                res ^= ans[i];
            }
            if(res == 0) puts("Arpa");
            else puts("Mojtaba");
        }
    }
    return 0;
}
