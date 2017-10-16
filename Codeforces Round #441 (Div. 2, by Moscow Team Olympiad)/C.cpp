#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> vec;
int n;
LL ten[15];

void dfs(int depth, LL sum, LL num) {
    if(depth == -1) {
        if(sum == n) vec.push_back(num);
        return;
    }
    if(sum > n) return;
    if(sum + (depth + 1) * 9 + ten[depth + 1] - 1 < n) return;
    for(int i = 0; i <= 9; ++i) {
        dfs(depth - 1, sum + i * (ten[depth] + 1), num * 10 + i);
    }
}

int main() {
    ten[0] = 1;
    for(int i = 1; i <= 12; ++i) ten[i] = ten[i - 1] * 10;
    scanf("%d", &n);
    vec.clear();
    dfs(10, 0, 0);
    sort(vec.begin(), vec.end());
    int len = vec.size();
    printf("%d\n", len);
    for(int i = 0; i < len; ++i) {
        printf("%d\n", vec[i]);
    }
    return 0;
}
