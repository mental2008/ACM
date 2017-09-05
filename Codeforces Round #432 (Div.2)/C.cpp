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
int node[1005][5];
int n;
vector<int> vec;
double standard;

double cal(int x, int y, int z) {
    double res = 0;
    for(int i = 0; i < 5; ++i) {
        res += (node[y][i] - node[x][i]) * (node[z][i] - node[x][i]);
    }
    return res;
}

bool judge(int x) {
    for(int i = 0; i < n; ++i) {
        if(i == x) continue;
        for(int j = 0; j < n; ++j) {
            if(j == x || j == i) continue;
            double a = cal(x, i, j);
            double b = sqrt(cal(x, i, i));
            double c = sqrt(cal(x, j, j));
            double res = acos(a / (b * c));
            if(res < standard) return false;
        }
    }
    return true;
}

int main() {
    standard = acos(0);
    while(~scanf("%d", &n)) {
        vec.clear();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                scanf("%d", &node[i][j]);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(judge(i)) vec.push_back(i);
        }
        int len = (int)vec.size();
        printf("%d\n", len);
        for(int i = 0; i < len; ++i) {
            printf("%d%c", vec[i] + 1, (i == len - 1 ? '\n' : ' '));
        }
    }
    return 0;
}
